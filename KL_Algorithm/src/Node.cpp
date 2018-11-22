#include"Node.h"

using namespace std;

//Default constructor 
Node::Node()
{
	//Initialize the node
	id = 0;
	degrees = 0;
	partition = 0;
	I = 0;
	E = 0;
	swapped = false;
}

//Deconstructor
Node::~Node()
{
	//Delete the connections
	//delete[] connections;
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
	connections = new int[degreeNum];

	//Loop and setup the connections array
	for (int i = 0; i < degreeNum; i++) {
		//Add the connection to the array
		connections[i] = shared[i];
	}
}

/*---------------------------------------------------------------
Class function:	getConnection (Node class)
Input(s):		int i - Index of the connection array
Output:			int - ID of the node sharing an edge
Description:	Obtains the ID of the current shared edge.
---------------------------------------------------------------*/
int Node::getConnection(int i)
{
	//Return the ID of the node that shares the edge
	return connections[i];
}

/*---------------------------------------------------------------
Class function:	getDegree (Node class)
Input(s):		Node
Output:			int - The number of degrees the node has.
Description:	Obtains number of degrees for the current node.
---------------------------------------------------------------*/
int Node::getDegree()
{
	//Return the number of degrees
	return degrees;
}

/*---------------------------------------------------------------
Class function:	setIE (Node class)
Input(s):		int iCost - Internal cost of the node
				int eCost - External cost of the node
Output:			void (none)
Description:	Set the internal & external cost values for the
	node.
---------------------------------------------------------------*/
void Node::setIE(int iCost, int eCost)
{
	//Set the internal cost for the node
	I = iCost;

	//Set the external cost for the node
	E = eCost;
}

/*---------------------------------------------------------------
Class function:	setD (Node class)
Input(s):		None
Output:			void (none)
Description:	Set the D values for the node.
---------------------------------------------------------------*/
void Node::setD()
{
	//Set the D value for the node
	D = E - I;
}

/*---------------------------------------------------------------
Class function:	getD (Node class)
Input(s):		None
Output:			int - D value for the node.
Description:	Obtain the D value from the node.
---------------------------------------------------------------*/
int Node::getD()
{
	//Return the D value
	return D;
}

/*---------------------------------------------------------------
Class function:	mark (Node class)
Input(s):		None
Output:			void (none)
Description:	Marks the node as being swapped
---------------------------------------------------------------*/
void Node::mark()
{
	//Set swapped to true
	swapped = true;
}

/*---------------------------------------------------------------
Class function:	mark (Node class)
Input(s):		None
Output:			void (none)
Description:	Marks the node as being unswapped
---------------------------------------------------------------*/
void Node::unmark()
{
	//Set swapped to true
	swapped = false;
}

/*---------------------------------------------------------------
Class function:	getSwapped (Node class)
Input(s):		None
Output:			bool - Swapped value
Description:	Obtain the swapped value from the node.
---------------------------------------------------------------*/
bool Node::getSwapped()
{
	//Return the D value
	return swapped;
}