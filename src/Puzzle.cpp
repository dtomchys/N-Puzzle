#include "../inc/Puzzle.hpp"

Puzzle::Puzzle() {}

void Puzzle::setInitialState(PUZZLE &map, size_t size, HeuristicFunction func) {
    this->_boardSize = size;
    this->_startState = map;
    switch (func) {
        case E_MANHATTAN: {
            this->_heuristic = &Puzzle::_misplacedTiles;
            break;
        }
        default: {
            this->_heuristic = &Puzzle::_manhattanDistance;
            break;
        }
    }
    this->_targetState = this->_countTargetState();
    this->_targetCoords = this->_countTargetCoords();

        for(int y=0; y < this->_startState.size();++y) {
        for(int x=0;x<this->_startState[y].size();++x) {
            std::cout<<this->_startState[y][x]<< " ";
        }
        std::cout<<std::endl;
    }
}

std::string Puzzle::generateUniqueKey(PUZZLE const &puzzle)
{
    std::string uniqueKey;

    for (int y = 0; y < this->_boardSize; ++y) {
        for (int x = 0; x < this->_boardSize; ++x) {
            uniqueKey += puzzle[y][x] + '0';
        }
    }

    return uniqueKey;
}

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
            h += this->rowConflict(node, currentTile);
            h += this->columnConflict(node, currentTile);
        }
    }

    return h * 2 + this->_manhattanDistance(node);
}

unsigned int Puzzle::rowConflict(Node *node, COORDS current)
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

unsigned int Puzzle::columnConflict(Node *node, COORDS current)
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

Node* Puzzle::getNextNode(Node *current, COORDS tile)
{
    Node *next = new Node();

    next->puzzle = current->puzzle;
    std::swap(next->puzzle[current->emptyTile.first][current->emptyTile.second], next->puzzle[tile.first][tile.second]);
    next->parent = current;
    next->emptyTile = tile;
    next->g = current->g + 1;
    next->h = (this->*_heuristic)(next);
    next->f = next->g + next->h;
    next->uniqueKey = this->generateUniqueKey(next->puzzle);

    return next;
}

std::list<Node *> Puzzle::checkNeighboringNodes(Node *current)
{
    std::list<Node *> neighbors;

    if (current->emptyTile.first > 0) {
        neighbors.push_back(this->getNextNode(current,
                std::make_pair(current->emptyTile.first - 1, current->emptyTile.second)));
    }

    if (current->emptyTile.second < this->_boardSize - 1) {
        neighbors.push_back(this->getNextNode(current,
                                              std::make_pair(current->emptyTile.first, current->emptyTile.second + 1)));
    }

    if (current->emptyTile.first < this->_boardSize - 1) {
        neighbors.push_back(this->getNextNode(current,
                std::make_pair(current->emptyTile.first + 1, current->emptyTile.second)));
    }

    if (current->emptyTile.second > 0) {
        neighbors.push_back(this->getNextNode(current,
                                              std::make_pair(current->emptyTile.first, current->emptyTile.second - 1)));
    }

    return neighbors;
}


// std::vector<unsigned int> Puzzle::boardToVector()
// {
//     std::vector<unsigned int> row;

//     for (size_t y = 0; y < this->_boardSize; y++) {
//         for (size_t x = 0; x < this->_boardSize; x++) {
//             row.push_back(this->_startState[y][x]);
//         }
//     }

//     return row;
// }

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

bool Puzzle::solve()
{
    auto cmp = [](Node *left, Node *right) { return (left->f > right->f); };
    std::priority_queue<Node *, std::vector<Node *>,  decltype(cmp)> nodes(cmp);
    std::map<std::string, Node *> opened;
    std::map<std::string, Node *> closed;

    Node *start = new Node();
    Node *current;
    std::list<Node *> all;

    start->puzzle = this->_startState;
    start->h = (this->*_heuristic)(start);
    start->f = start->h;
    start->emptyTile = this->_findTilePosition(start->puzzle);
    start->uniqueKey = this->generateUniqueKey(start->puzzle);
    all.push_back(start);

    nodes.push(start);
    opened[start->uniqueKey] = start;
    int i = 0, j = 0;
    while (!nodes.empty()) {
        current = nodes.top();

        if (!current->h) {
            this->printPath(current);
            for (auto it = all.begin(); it != all.end(); ++it) {
                delete (*it);
            }
            return true;
        }

        nodes.pop();

        if (closed.find(current->uniqueKey) != closed.end()) {
            continue;
        }

        closed[current->uniqueKey] = current;

        std::list<Node *> neighbors = this->checkNeighboringNodes(current);

        for (auto &neighbor : neighbors) {
            if (closed.find(neighbor->uniqueKey) != closed.end()) {
                delete neighbor;
                continue;
            }

            if (opened.find(neighbor->uniqueKey) != opened.end()) {
                if (opened[neighbor->uniqueKey]->g <= neighbor->g) {
                    delete neighbor;
                    continue ;
                }
            }

            opened[neighbor->uniqueKey] = neighbor;
            nodes.push(neighbor);
            all.push_back(neighbor);
        }
    }

    return true;
}


std::map<unsigned int, COORDS> Puzzle::_countTargetCoords()
{
    std::map<unsigned int, COORDS> targetCoords;

    for(int y = 0; y < this->_boardSize; ++y) {
        for(int x=0;x<this->_boardSize; ++x) {
            targetCoords[this->_targetState[y][x]] = std::make_pair(y, x);
        }
    }

    return targetCoords;
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
