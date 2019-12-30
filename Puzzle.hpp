#ifndef PUZZLE_HPP
# define PUZZLE_HPP

# include "npuzzle.hpp"

class Puzzle
{
	public:
		Puzzle();
		~Puzzle();

	private:
		PUZZLE startState; // 2D vector array that describes start state of N-puzzle
		PUZZLE finalState; // 2D vector array that describes target state of N-puzzle
		size_t boardSize;
}

#endif