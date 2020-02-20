#ifndef PUZZLE_HPP
# define PUZZLE_HPP

# define RIGHT std::make_pair(0, 1)
# define LEFT std::make_pair(0, -1)
# define UP std::make_pair(-1, 0)
# define DOWN std::make_pair(1, 0)

# include "general.h"

const std::map <std::pair <int, int>, std::string> moves = {
        { UP, "UP" },
        { DOWN, "DOWN" },
        { LEFT, "LEFT" },
        { RIGHT, "RIGHT" }
};

class Puzzle;
typedef unsigned int (Puzzle::*PuzzleHeuristic)(Node *);  // Please do this!
typedef std::pair <unsigned int, unsigned int> COORDS;

struct Info
{
    std::map<std::string, Node *> opened;
    unsigned int selectedOpened;
    Node *target;
};

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

    COORDS _findTilePosition(PUZZLE state, unsigned int tile = 0);
    unsigned int _manhattanDistance(Node *current);
    unsigned int _misplacedTiles(Node *node);
    unsigned int _linearConflict(Node *node);
    PUZZLE _countTargetState(void);
    std::list<Node *> _checkNeighboringNodes(Node *current);
    //Node* getNextNode(Node *current, COORDS tile);
    Node* _getNextNode(Node *current, std::pair <int, int> tile);
    std::vector<unsigned int> boardToVector();
    unsigned int _rowConflict(Node *node, COORDS current);
    unsigned int _columnConflict(Node *node, COORDS current);
    std::map<unsigned int, COORDS> _countTargetCoords();
    void _printInfo();
    void _printState(const PUZZLE &puzzle);
    std::list<Node *> _getPath();

    PUZZLE _startState;
    PUZZLE _targetState;
    unsigned int _maxTile;
    PuzzleHeuristic _heuristic;
    std::map<unsigned int, COORDS> _targetCoords;
    size_t _boardSize;
    Info _info;
};

#endif