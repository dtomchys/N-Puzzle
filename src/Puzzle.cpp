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
    this->_maxTile = this->_boardSize * this->_boardSize;
    this->_targetState = this->_countTargetState();
    this->_targetCoords = this->_countTargetCoords();
    this->_printState(this->_startState);
}

//std::string Puzzle::generateUniqueKey(PUZZLE const &puzzle)
//{
//    std::string uniqueKey;
//
//    for (int y = 0; y < this->_boardSize; ++y) {
//        for (int x = 0; x < this->_boardSize; ++x) {
//            uniqueKey += puzzle[y][x] + '0';
//        }
//    }
//
//    return uniqueKey;
//}

Puzzle& Puzzle::getInstance()
{
	static Puzzle instance;

	return instance;
}

COORDS Puzzle::_findTilePosition(PUZZLE state, unsigned int tileValue)
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

unsigned int Puzzle::_linearConflict(Node *node)
{
    unsigned int h = 0;
    COORDS currentTile;

    for (int y = 0; y < this->_boardSize; ++y) {
        for (int x = 0; x < this->_boardSize; ++x) {
            currentTile = std::make_pair(y, x);
            h += this->_rowConflict(node, currentTile);
            h += this->_columnConflict(node, currentTile);
        }
    }

    return h * 2 + this->_manhattanDistance(node);
}

unsigned int Puzzle::_rowConflict(Node *node, COORDS current)
{
    unsigned int h = 0;

    for (int i = 0; i < this->_boardSize; ++i) {
        if (node->puzzle[current.first][current.second] != node->puzzle[current.first][i] &&
            current.first == this->_targetCoords[node->puzzle[current.first][current.second]].first &&
            current.first == this->_targetCoords[node->puzzle[current.first][i]].first &&
            current.second > i &&
            this->_targetCoords[node->puzzle[current.first][current.second]].second <= this->_targetCoords[node->puzzle[current.first][i]].second
        ) {
            h++;
        }
    }

    return h;
}

unsigned int Puzzle::_columnConflict(Node *node, COORDS current)
{
    static int z = 0;
    unsigned int h = 0;

    for (int i = 0; i < this->_boardSize; ++i) {
        if (node->puzzle[current.first][current.second] != node->puzzle[i][current.second] &&
                current.second == this->_targetCoords[node->puzzle[current.first][current.second]].second &&
                current.second == this->_targetCoords[node->puzzle[i][current.second]].second &&
                current.first > i &&
                this->_targetCoords[node->puzzle[current.first][current.second]].first <= this->_targetCoords[node->puzzle[i][current.second]].first
            ) {
            h++;
        }
    }

    return h;
}

unsigned int Puzzle::_misplacedTiles(Node *node)
{
    unsigned int h = 0;

    for (int y = 0; y < this->_boardSize; ++y) {
        for (int x = 0; x < this->_boardSize; ++x) {
            if (node->puzzle[y][x] != this->_targetState[y][x]) {
                h++;
            }
        }
    }

    return h;
}

unsigned int Puzzle::_manhattanDistance(Node *node)
{
    unsigned int h = 0;
    COORDS finalPosition;

    for (int y = 0; y < this->_boardSize; ++y) {
        for (int x = 0; x < this->_boardSize; ++x) {
            if (node->puzzle[y][x] != this->_targetState[y][x]) {
                finalPosition = this->_findTilePosition(this->_targetState,
                                                                                              node->puzzle[y][x]);

                h += std::abs((int)(y - finalPosition.first)) + std::abs((int)(x - finalPosition.second));
            }
        }
    }

    return h;
}

//Node* Puzzle::getNextNode(Node *current, COORDS tile)
//{
//    Node *next = new Node();
//
//    next->puzzle = current->puzzle;
//    std::swap(next->puzzle[current->emptyTile.first][current->emptyTile.second], next->puzzle[tile.first][tile.second]);
//    next->parent = current;
//    next->emptyTile = tile;
//    next->g = current->g + 1;
//    next->h = (this->*_heuristic)(next);
//    next->f = next->g + next->h;
//    next->generateUniqueKey();
//
//    return next;
//}

Node* Puzzle::_getNextNode(Node *current, std::pair <int, int> tile)
{
    Node *next = new Node();

    next->puzzle = current->puzzle;
    next->emptyTile = std::make_pair(current->emptyTile.first + tile.first, current->emptyTile.second + tile.second);
    std::swap(next->puzzle[current->emptyTile.first][current->emptyTile.second], next->puzzle[next->emptyTile.first][next->emptyTile.second]);
    next->parent = current;
    next->g = current->g + 1;
    next->h = (this->*_heuristic)(next);
    next->f = next->g + next->h;
    next->generateUniqueKey();
    next->move = moves.at(tile);

    return next;
}

std::list<Node *> Puzzle::_checkNeighboringNodes(Node *current)
{
    std::list<Node *> neighbors;

    if (current->emptyTile.first > 0) {
        neighbors.push_back(this->_getNextNode(current, UP));
    }

    if (current->emptyTile.second < this->_boardSize - 1) {
        neighbors.push_back(this->_getNextNode(current, RIGHT));
    }

    if (current->emptyTile.first < this->_boardSize - 1) {
        neighbors.push_back(this->_getNextNode(current, DOWN));
    }

    if (current->emptyTile.second > 0) {
        neighbors.push_back(this->_getNextNode(current, LEFT));
    }

    return neighbors;
}

//std::list<Node *> Puzzle::checkNeighboringNodes(Node *current)
//{
//    std::list<Node *> neighbors;
//
//    if (current->emptyTile.first > 0) {
//        neighbors.push_back(this->getNextNode(current,
//                std::make_pair(current->emptyTile.first - 1, current->emptyTile.second)));
//    }
//
//    if (current->emptyTile.second < this->_boardSize - 1) {
//        neighbors.push_back(this->getNextNode(current,
//                                              std::make_pair(current->emptyTile.first, current->emptyTile.second + 1)));
//    }
//
//    if (current->emptyTile.first < this->_boardSize - 1) {
//        neighbors.push_back(this->getNextNode(current,
//                std::make_pair(current->emptyTile.first + 1, current->emptyTile.second)));
//    }
//
//    if (current->emptyTile.second > 0) {
//        neighbors.push_back(this->getNextNode(current,
//                                              std::make_pair(current->emptyTile.first, current->emptyTile.second - 1)));
//    }
//
//    return neighbors;
//}

std::list<Node *> Puzzle::_getPath()
{
    std::list<Node *> path;

    while (this->_info.target) {
        path.push_front(this->_info.target);
        this->_info.target = this->_info.target->parent;
    }

    return path;
}

void Puzzle::_printInfo()
{
    std::list<Node *> path = this->_getPath();
    int i = 0;

    std::cout << "Complexity in time: " << this->_info.selectedOpened << std::endl;
    std::cout << "Complexity in size: " << this->_info.opened.size() << std::endl;
    std::cout << "Number of moves: " << path.size() - 1 << std::endl;
    std::cout << "The ordered sequence of states: " << std::endl;

    for (auto it = path.begin(); it != path.end(); ++it) {
        std::cout << "Move " << i << ": " << (*it)->move << std::endl;
        this->_printState((*it)->puzzle);
        std::cout << std::endl;
        i++;
    }
}

void Puzzle::_printState(const PUZZLE &puzzle)
{
    unsigned int width = std::to_string(this->_maxTile).length() + 3;

    for(int y = 0; y < this->_boardSize; ++y)
    {
        for(int x = 0;x < this->_boardSize; ++x)
        {
            std::cout << std::left << std::setw(width) << puzzle[y][x];
        }
        std::cout << std::endl;
    }
}

bool Puzzle::solve()
{
    auto cmp = [](Node *left, Node *right) { return (left->f > right->f); };
    std::priority_queue<Node *, std::vector<Node *>,  decltype(cmp)> nodes(cmp);
    std::map<std::string, Node *> closed;

    Node *start = new Node();
    Node *current;
    std::list<Node *> all;

    start->puzzle = this->_startState;
    start->h = (this->*_heuristic)(start);
    start->f = start->h;
    start->emptyTile = this->_findTilePosition(start->puzzle);
    start->generateUniqueKey();
    all.push_back(start);

    nodes.push(start);
    this->_info.opened[start->uniqueKey] = start;
    int i = 0;
    while (!nodes.empty()) {
        current = nodes.top();

        nodes.pop();

        if (closed.find(current->uniqueKey) != closed.end()) {
            continue;
        }
        this->_info.selectedOpened++;

        if (!current->h) {
            this->_info.target = current;
            this->_printInfo();
            for (auto it = all.begin(); it != all.end(); ++it) {
                delete (*it);
            }
            return true;
        }

        closed[current->uniqueKey] = current;

        std::list<Node *> neighbors = this->_checkNeighboringNodes(current);

        for (auto &neighbor : neighbors) {
            if (closed.find(neighbor->uniqueKey) != closed.end()) {
                delete neighbor;
                continue;
            }

            if (this->_info.opened.find(neighbor->uniqueKey) != this->_info.opened.end()) {
                if (this->_info.opened[neighbor->uniqueKey]->g <= neighbor->g) {
                    delete neighbor;
                    continue ;
                }
            }

            this->_info.opened[neighbor->uniqueKey] = neighbor;
            nodes.push(neighbor);
            all.push_back(neighbor);
        }
        i++;
    }

    return true;
}


std::map<unsigned int, COORDS> Puzzle::_countTargetCoords()
{
    std::map<unsigned int, COORDS> targetCoords;

    for(int y = 0; y < this->_boardSize; ++y) {
        for(int x=0; x < this->_boardSize; ++x) {
            targetCoords[this->_targetState[y][x]] = std::make_pair(y, x);
        }
    }

    return targetCoords;
}

PUZZLE Puzzle::_countTargetState()
{
	unsigned int x = 0, y = 0, shift = 0, tile = 1;

	PUZZLE targetState(this->_boardSize, std::vector<unsigned int>(this->_boardSize, 0));

	while (shift < this->_boardSize / 2) {
		while (++x < this->_boardSize - shift and tile < this->_maxTile) { targetState[y][x - 1] = tile++; }
		while (++y < this->_boardSize - shift and tile < this->_maxTile) { targetState[y - 1][x - 1] = tile++; }
		while (--x > shift and tile < this->_maxTile) { targetState[y - 1][x] = tile++; }
		while (--y > shift and tile < this->_maxTile) { targetState[y][x] = tile++; }
		x = y = ++shift;
	}

	return targetState;
}
