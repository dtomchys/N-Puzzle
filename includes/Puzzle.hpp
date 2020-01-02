#ifndef PUZZLE_HPP
# define PUZZLE_HPP

# include "npuzzle.hpp"

class Puzzle;
typedef  void (Puzzle::*PuzzleHeuristic)();  // Please do this!

class Puzzle
{
public:
  static Puzzle& getInstance();

// Other non-static member functions
private:
    Puzzle();                              // Private constructor
    ~Puzzle() {}
    Puzzle(const Puzzle&);                 // Prevent copy-construction
    Puzzle& operator=(const Puzzle&);      // Prevent assignment

    void _countTargetState();

    PUZZLE _startState;
    PUZZLE _targetState;;
    size_t _boardSize;
    PuzzleHeuristic _heuristic;
    void _manhattanDistance();
};

#endif