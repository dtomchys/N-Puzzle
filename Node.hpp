#ifndef NODE_HPP
# define NODE_HPP

#include <vector>

class Node
{
	public:
		Node(std::vector<std::vector<int>> puzzle);
		~Node();
		void setParent(Node *parent);

	private:
		Node *parent;
};

#endif