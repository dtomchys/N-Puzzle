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

// Tile Puzzle::_findTilePosition(PUZZLE state, unsigned int tileValue)
// {
// 	std::vector<unsigned int>::iterator column;
// 	PUZZLE::iterator row;
// 	Tile tileCords;
// 	unsigned int x, y = 0;

//     for (row = state.begin(); row != state.end(); row++) {
//     	column = find(row->begin(), row->end(), tileValue);
//     	if(column != row->end()) {
//     		x = std::distance(row->begin(), column);
//     		break ;
//     	}
//     	y++;
//     }

//     tileCords.x = x;
//     tileCords.y = y;

//     return tileCords;
// }

unsigned int Puzzle::_manhattanDistance()
{
	unsigned int h = 0;

	for(int y = 0; y < this->_boardSize; ++y)
	{
		for(int x = 0;x < this->_boardSize; ++x)
		{
			if (this->_startState[y][x] != this->_targetState[y][x]) {
				h++;
			}
		}
	}

	return h;

	//std::cout << h << std::endl;
	// Tile startPosition = this->_findTilePosition(this->_startState, tile);
	// Tile targetPosition = this->_findTilePosition(this->_targetState, tile);

	// for(int y = 0; y < this->_boardSize; ++y)
	// {
	// 	for(int x = 0;x < this->_boardSize; ++x)
	// 	{
	// 		std::cout << this->_targetState[y][x] << std::ends;
	// 	}
	// }
	// std::cout << startPosition.x << std::endl;
	// std::cout << startPosition.y << std::endl;
	// std::cout << targetPosition.x << std::endl;
	// std::cout << targetPosition.y << std::endl;
}


void Puzzle::solve()
{
// 	std::list<Node*> openedList;
// 	std::list<Node*> closedList;
// 	unsigned int h = (this->*_heuristic)();
// 	//std::cout << h << std::endl;
// 	Node* node = new Node(this->_startState, h);
// 	std::list<Node*>::iterator it;
// 		openedList.push_back(node);

// //std::cout << node->h << std::endl;

// 	for(it=openedList.begin(); it!=openedList.end(); it++)
// 	{
// 	     std::cout << (*it)->h << std::endl; // compile error
// 	}

	std::list<Node> openedList;
	std::list<Node> closedList;
	unsigned int h = (this->*_heuristic)();
	//std::cout << h << std::endl;
	Node node = Node(this->_startState, h);
	std::list<Node>::iterator it;
		openedList.push_back(node);

	for(it=openedList.begin(); it!=openedList.end(); it++)
	{
	     std::cout << (*it).h << std::endl; // compile error
	}
	// 	if (openedList.empty()) {
	// 	std::cout << "empty" << std::endl;
	// }
	//std::cout << openedList.size() << std::endl;
	// while (!openedList.empty()) {

	// }
	// 	if (openedList.empty()) {
	// 	std::cout << "empty" << std::endl;
	// }
}

PUZZLE Puzzle::_countTargetState(void)
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