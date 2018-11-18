#include "Node.h"

using namespace std;

//Default constructor for node class
Node::Node()
{
	//Initialize the created node
	nodeID = 0;
	degree = 0;
	edges = new int(degree);
}

//Deconstructor for node class
Node::~Node()
{
}

void Node::setNodeID(int ID)
{
	//Set the node's unique id
	nodeID = ID;
}

void Node::setDegree(int numDegree)
{
	//Set the degree number
	degree = numDegree;
}


int Node::getID()
{
	//Return the node's unique ID
	return nodeID;
}

int Node::getDegree()
{
	//Return the node's degree
	return degree;
}