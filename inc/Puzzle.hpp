#ifndef PUZZLE_HPP
# define PUZZLE_HPP

# define EVEN(number) ((number % 2 == 0) ? 1:0)
# define ABS(number) ((number < 0) ? -number : number)

# include "general.h"
class Puzzle;
//typedef unsigned int (Puzzle::*PuzzleHeuristic)(PUZZLE);  // Please do this!
typedef unsigned int (Puzzle::*PuzzleHeuristic)(Node *);  // Please do this!

class Puzzle
{
public:
  static Puzzle& getInstance();
  void setInitialState(PUZZLE &map, size_t size, HeuristicFunction func);
  bool solve();

// Other non-static member functions
private:
    Puzzle();                              // Private constructor
    ~Puzzle() {}
    Puzzle(const Puzzle&);                 // Prevent copy-construction
    Puzzle& operator=(const Puzzle&);      // Prevent assignment

    std::pair <unsigned int, unsigned int> _findTilePosition(PUZZLE state, unsigned int tile = 0);
    unsigned int _manhattanDistance(Node *current);
    PUZZLE _countTargetState(void);
    std::list<Node *> checkNeighboringNodes(Node *current);
    Node* getNextNode(Node *current, std::pair <unsigned int, unsigned int> tile);
    std::vector<unsigned int> boardToVector();
    void printPath(Node *target);
    std::string generateUniqueKey(PUZZLE const &puzzle);

    PUZZLE _startState;
    PUZZLE _targetState;
    PuzzleHeuristic _heuristic;
    size_t _boardSize;
};

#endif