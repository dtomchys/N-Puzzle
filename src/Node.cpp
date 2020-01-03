#include "../inc/general.h"

Node::Node(PUZZLE puzzle, unsigned int h)
{
	//std::cout << "ss" << std::endl;
	this->puzzle = puzzle;
	this->h = h;
}

void Node::setParent(Node *parent)
{
	this->parent = parent;
}

Node::~Node() { }