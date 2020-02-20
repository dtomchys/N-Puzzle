#ifndef NODE_HPP
# define NODE_HPP

# include "general.h"

struct Node
{
    std::pair <unsigned int, unsigned int> emptyTile;
    Node *parent;
    PUZZLE puzzle;
    unsigned int f;
    unsigned int g;
    unsigned int h;
    std::string uniqueKey;
    std::string move;

    Node(): f(0),
            g(0),
            h(0),
            parent(NULL)
    {};

    void generateUniqueKey(void) {
        unsigned int size;

        size = this->puzzle.size();

        for (int y = 0; y < size; ++y) {
            for (int x = 0; x < size; ++x) {
                this->uniqueKey += this->puzzle[y][x] + '0';
            }
        }
    }
};

#endif