#ifndef NODE_HPP
# define NODE_HPP

# include "Puzzle.hpp"

class Node
{
	public:
		Node(PUZZLE puzzle, unsigned int h);
		~Node();
		void setParent(Node *parent);

		unsigned int h;

	private:
		Node *parent;
		PUZZLE puzzle;
};

#endif