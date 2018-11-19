#include"Node.h"

using namespace std;

//Default constructor 
Node::Node()
{
	//Initialize the node
	id = 0;
	degrees = 0;
	partition = 0;
}

//Deconstructor
Node::~Node()
{
	//Delete the connections
	delete[] connections;
}

/*---------------------------------------------------------------
Class function:	nodeSetup (Node class)
Input(s):		int nodeID - Unique node id number
Output:			void (none)
Description:	Sets up the initialize node by setting the node
	id number and what partition the node is currently in.
---------------------------------------------------------------*/
void Node::nodeSetup(int nodeID, int partNum) {
	//Initialize the node ID
	id = nodeID;

	//Initialize the partition number
	partition = partNum;
}

/*---------------------------------------------------------------
Class function:	getNodeID (Node class)
Input(s):		None
Output:			int - The unique ID for the node
Description:	Displays the node's unique ID number.
---------------------------------------------------------------*/
int Node::getNodeID()
{
	//Return the unique node ID
	return id;
}

/*---------------------------------------------------------------
Class function:	setDegree (Node class)
Input(s):		int degreeNum - Degree of the node
				int* shared - Shared connections array
Output:			void (none)
Description:	Sets the degree number for the node, initializes
	the connection array, & add connections to the connection
	array.
---------------------------------------------------------------*/
void Node::setDegree(int degreeNum, int* shared)
{
	//Set the degree
	degrees = degreeNum;

	//Initialize the integer connections array
	connections = new unsigned int[degreeNum];

	//Loop and setup the connections array
	for (int i = 0; i < degreeNum; i++) {
		//Add the connection to the array
		connections[i] = shared[i];
	}
}