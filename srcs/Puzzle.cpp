#include "Puzzle.hpp"
#include <iostream>
#include <cmath>

Puzzle::Puzzle() {
	//std::cout << "Constructor" << std::endl;
	this->_startState = {{ 3, 2, 6 },
					{ 1, 4, 0 },
					{ 8, 7, 5 }};
	this->_boardSize = 7;
	this->_heuristic = &Puzzle::_manhattanDistance;
	this->_countTargetState();
}

Puzzle& Puzzle::getInstance()
{
	static Puzzle instance;

	return instance;
}

void Puzzle::_manhattanDistance()
{
	std::cout << "manh" << std::endl;
}

void Puzzle::_countTargetState()
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

	this->_targetState = targetState;
	//(this->*_heuristic)();
	// for(int y=0;y<targetState.size();++y)
 //    {
 //        for(int x=0;x<targetState[y].size();++x)
 //        {
 //            std::cout<<targetState[y][x]<<std::ends;
 //        }
 //        std::cout<<std::endl;
 //    }
}