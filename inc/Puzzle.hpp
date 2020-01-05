#ifndef PUZZLE_HPP
# define PUZZLE_HPP

# include "general.h"
class Puzzle;
typedef unsigned int (Puzzle::*PuzzleHeuristic)(void);  // Please do this!

// struct Tile
// {
// 	unsigned int x, y;
// };

class Puzzle
{
public:
  static Puzzle& getInstance();
  void setInitialState(PUZZLE &map, size_t size, HeuristicFunction func);
  void solve();

// Other non-static member functions
private:
    Puzzle();                              // Private constructor
    ~Puzzle() {}
    Puzzle(const Puzzle&);                 // Prevent copy-construction
    Puzzle& operator=(const Puzzle&);      // Prevent assignment

    //Tile _findTilePosition(PUZZLE state, unsigned int tile);
    unsigned int _manhattanDistance(void);
    PUZZLE _countTargetState(void);

    PUZZLE _startState;
    PUZZLE _targetState;;
    PuzzleHeuristic _heuristic;
    size_t _boardSize;
};

#endif