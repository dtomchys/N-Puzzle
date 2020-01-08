#ifndef NODE_HPP
# define NODE_HPP

# include "general.h"
//class Node;
//
//struct Tile
//{
//    unsigned int x, y;
//};

class Node
{
	public:
        Node(): f(0),
                g(0),
                h(0),
                parent(NULL)
        {};
		~Node();

        std::pair <unsigned int, unsigned int> emptyTile;
		Node *parent;
		PUZZLE puzzle;
        unsigned int f;
        unsigned int g;
        unsigned int h;
};

#endif