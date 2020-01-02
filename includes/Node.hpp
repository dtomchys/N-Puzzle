#ifndef NODE_HPP
# define NODE_HPP

# include "Puzzle.hpp"

class Node
{
	public:
		Node(PUZZLE puzzle);
		~Node();
		void setParent(Node *parent);

	private:
		Node *parent;
		PUZZLE puzzle;

};

#endif