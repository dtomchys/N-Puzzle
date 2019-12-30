#include "Node.hpp"

Node::Node(std::vector<std::vector<int>> puzzle)
{
	this->puzzle = puzzle;
}

void Node::setParent(Node *parent)
{
	this->parent = parent;
}

Node::~Node() { }