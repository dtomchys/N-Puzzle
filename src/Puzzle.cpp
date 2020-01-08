#include "../inc/Puzzle.hpp"

Puzzle::Puzzle() {}

void Puzzle::setInitialState(PUZZLE &map, size_t size, HeuristicFunction func) {
    this->_boardSize = size;
    this->_startState = map;
    switch (func) {
        case E_MANHATTAN: {
            this->_heuristic = &Puzzle::_manhattanDistance;
            break;
        }
        default: {
            this->_heuristic = &Puzzle::_manhattanDistance;
            break;
        }
    }
    this->_targetState = this->_countTargetState();
        for(int y=0; y < this->_startState.size();++y) {
        for(int x=0;x<this->_startState[y].size();++x) {
            std::cout<<this->_startState[y][x]<< " ";
        }
        std::cout<<std::endl;
    }
}

Puzzle& Puzzle::getInstance()
{
	static Puzzle instance;

	return instance;
}

std::pair <unsigned int, unsigned int> Puzzle::_findTilePosition(PUZZLE state, unsigned int tileValue)
{
    std::vector<unsigned int>::iterator column;
    PUZZLE::iterator row;
    unsigned int x = 0, y = 0;
    for (row = state.begin(); row != state.end(); row++) {
        column = find(row->begin(), row->end(), tileValue);
        if(column != row->end()) {
            x = std::distance(row->begin(), column);
            break ;
        }
        y++;
    }

    return std::make_pair(y, x);
}

unsigned int Puzzle::_manhattanDistance(Node *node)
{
    unsigned int h = 0;

    if (!node->parent) {
        for (int y = 0; y < this->_boardSize; ++y) {
            for (int x = 0; x < this->_boardSize; ++x) {
                //if (node->puzzle[y][x] == 0) { continue; }

                if (node->puzzle[y][x] != this->_targetState[y][x]) {
                    std::pair<unsigned int, unsigned int> finalPosition = this->_findTilePosition(this->_targetState,
                                                                                                  node->puzzle[y][x]);
                    int temp1 = y - finalPosition.first;
                    int temp2 = x - finalPosition.second;
                    //std::cout << ABS(temp1) + ABS(temp2) << std::endl;
                    h += ABS(temp1) + ABS(temp2);
                }
            }
        }
    } else {
        std::pair<unsigned int, unsigned int> finalPosition = this->_findTilePosition(this->_targetState,
                                                                                      node->parent->puzzle[node->emptyTile.first][node->emptyTile.second]);
        int temp1 = node->emptyTile.first - finalPosition.first;
        int temp2 = node->emptyTile.second - finalPosition.second;
        h = node->parent->h - (ABS(temp1) + ABS(temp2));
        temp1 = node->parent->emptyTile.first - finalPosition.first;
        temp2 = node->parent->emptyTile.second - finalPosition.second;
        h += ABS(temp1) + ABS(temp2);


        finalPosition = this->_findTilePosition(this->_targetState);
        temp1 = node->parent->emptyTile.first - finalPosition.first;
        temp2 = node->parent->emptyTile.second - finalPosition.second;
        h -= (ABS(temp1) + ABS(temp2));
        temp1 = node->emptyTile.first - finalPosition.first;
        temp2 = node->emptyTile.second - finalPosition.second;
        h += ABS(temp1) + ABS(temp2);
    }

    return h;
}

Node* Puzzle::getNextNode(Node *current, std::pair <unsigned int, unsigned int> tile)
{
    Node *next = new Node();

    next->puzzle = current->puzzle;
    std::swap(next->puzzle[current->emptyTile.first][current->emptyTile.second], next->puzzle[tile.first][tile.second]);
    next->parent = current;
    next->emptyTile = tile;
    next->g = current->g + 1;
    next->h = (this->*_heuristic)(next);
    next->f = next->g + next->h;

    return next;
}

std::list<Node *> Puzzle::checkNeighboringNodes(Node *current)
{
    std::list<Node *> neighbors;

    if (current->emptyTile.second > 0) {
        neighbors.push_back(this->getNextNode(current,
                std::make_pair(current->emptyTile.first, current->emptyTile.second - 1)));
    }

    if (current->emptyTile.second < this->_boardSize - 1) {
        neighbors.push_back(this->getNextNode(current,
                std::make_pair(current->emptyTile.first, current->emptyTile.second + 1)));
    }

    if (current->emptyTile.first > 0) {
        neighbors.push_back(this->getNextNode(current,
                std::make_pair(current->emptyTile.first - 1, current->emptyTile.second)));
    }

    if (current->emptyTile.first < this->_boardSize - 1) {
        neighbors.push_back(this->getNextNode(current,
                std::make_pair(current->emptyTile.first + 1, current->emptyTile.second)));
    }

    return neighbors;
}

Node* Puzzle::checkAvailability(std::list<Node *> &openedList, Node *next) {
    auto it = find_if(openedList.begin(), openedList.end(), [next](Node *opened) -> bool {
        return (opened->puzzle == next->puzzle);
    });

    if (openedList.end() != it ) {
        return *it;
    }

    return NULL;
}

std::vector<unsigned int> Puzzle::boardToVector()
{
    std::vector<unsigned int> row;

    for (size_t y = 0; y < this->_boardSize; y++) {
        for (size_t x = 0; x < this->_boardSize; x++) {
            row.push_back(this->_startState[y][x]);
        }
    }

    return row;
}

void Puzzle::printPath(Node *target)
{
    int i = 0;

    while (target->parent) {
        std::cout << i++ + 1 << std::endl;

        for(int y=0; y < this->_boardSize;++y)
        {
            for(int x=0;x < this->_boardSize;++x)
            {
                std::cout<< target->puzzle[y][x]<<std::ends;
            }
            std::cout<<std::endl;
        }

        target = target->parent;
    }
}

void Puzzle::addOpenedNode(std::list<Node *> &list, Node *openedNode)
{
    std::list<Node *>::iterator it;

    for (it = list.begin(); it != list.end(); ++it) {
        if ((*it)->f >= openedNode->f) {
            list.insert(it, openedNode);
            return ;
        }
    }

    list.push_back(openedNode);
}

bool Puzzle::solve()
{
	std::list<Node *> openedList;
	std::list<Node *> closedList;
    std::list<Node *>::iterator it;
    Node *temp;

	Node *start = new Node();

    start->puzzle = this->_startState;
    start->h = (this->*_heuristic)(start);
    start->f = start->h;
    start->emptyTile = this->_findTilePosition(start->puzzle);

    openedList.push_back(start);
int i = 0;
    while (!openedList.empty()) {
        it = openedList.begin();

        if ((*it)->h == 0) {
            this->printPath((*it));
            return true;
        }

        closedList.splice(closedList.begin(), openedList, it);

        std::list<Node *> neighbors = this->checkNeighboringNodes((*it));

        for (auto &neighbor : neighbors) {

            if (this->checkAvailability(closedList, neighbor)) { continue; }

            if ((temp = this->checkAvailability(openedList, neighbor))) {
                if (temp->g > neighbor->g) {
                    openedList.remove(temp);
                }
            }

            this->addOpenedNode(openedList, neighbor);
        }
        i++;
    }
    return false;
}

PUZZLE Puzzle::_countTargetState()
{
	unsigned int x = 0, y = 0, shift = 0, tile = 1;
	unsigned int maxTile = this->_boardSize * this->_boardSize;

	PUZZLE targetState(this->_boardSize, std::vector<unsigned int>(this->_boardSize, 0));

	while (shift < this->_boardSize / 2) {
		while (++x < this->_boardSize - shift and tile < maxTile) { targetState[y][x - 1] = tile++; }
		while (++y < this->_boardSize - shift and tile < maxTile) { targetState[y - 1][x - 1] = tile++; }
		while (--x > shift and tile < maxTile) { targetState[y - 1][x] = tile++; }
		while (--y > shift and tile < maxTile) { targetState[y][x] = tile++; }
		x = y = ++shift;
	}

	return targetState;
}
