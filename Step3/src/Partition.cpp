#include"Partition.h"

using namespace std;

//Default constructor
Partition::Partition(int size, int number)
{
	//Initialize the size of the partition
	nodeNum = size;

	//Initialize the partition number
	partitionNum = number;

	//Initialize the index
	index = 0;

	//Initialize the node array
	nodes = new Node[nodeNum];
}

//Copy Constuctor
Partition::Partition(int size, int number, Node* otherNodes)
{
	//Initialize the size of the partition
	nodeNum = size;

	//Initialize the partition number
	partitionNum = number;

	//Initialize the node array
	nodes = otherNodes;
}

//Deconstructor
Partition::~Partition()
{
	//Delete the nodes
	delete[] nodes;
}

/*------------------------------------------------------------------------------
Class Function:	addNode (class Partition)
Input(s):		int nodeID - The unique ID of the node
Output:			void(None)
Definition:		Adds a single node to the array of nodes in the partition.
------------------------------------------------------------------------------*/
void Partition::addNode(int nodeID, int partNum)
{
	//Add the node to the current index location
	nodes[index].nodeSetup(nodeID, partNum);

	//Increment the index number
	index++;
}

/*------------------------------------------------------------------------------
Class Function:	displayNodes (class Partition)
Input(s):		None
Output:			void(None)
Definition:		Displays all the nodes in the partition.
------------------------------------------------------------------------------*/
void Partition::displayNodes()
{
	//Display current partion number
	cout << "Partition " << partitionNum << " (";

	//Loop through the nodes in the partition
	for (int i = 0; i < nodeNum; i++) {
		if (i < nodeNum - 1) {
			//Display the current node ID
			cout << nodes[i].getNodeID() << " ";
		}
		else
			//Display the current node ID
			cout << nodes[i].getNodeID();
	}

	//Close the displayed partition
	cout << ")" << endl;
}

/*------------------------------------------------------------------------------
Class Function:	setNodeDegrees (class Partition)
Input(s):		int i - The node's index number
				int degree - The degree of the current node
				int* connections - The array of shared connections
Output:			void(None)
Definition:		Displays all the nodes in the partition.
------------------------------------------------------------------------------*/
void Partition::setNodeDegree(int i, int degrees, int* connections)
{
	//Add the number of degrees to the node
	nodes[i].setDegree(degrees, connections);
}

/*------------------------------------------------------------------------------
Class Function:	costFunction (class Partition)
Input(s):		None
Output:			int - The cost of the partition
Definition:		Calculates the cost of the partition.
------------------------------------------------------------------------------*/
int Partition::costFunction()
{
	//Declare local variables
	int cost = 0;
	bool found;

	//Loop through the set of nodes in the partition
	for (int i = 0; i < nodeNum; i++) {

		//Loop through the current ID's shared connection list
		for (int j = 0; j < nodes[i].getDegree(); j++) {
			//Set found equal to false
			found = false;

			//Loop through the set of nodes in the partition
			for (int k = 0; k < nodeNum; k++) {

				//Check if other node's ID is equal to the connection ID
				if (nodes[i].getConnection(j) == nodes[k].getNodeID()) {
					//Change found to true
					found = true;
					break;
				}
			}
			//Check if match was not found
			if (!found) {
				//Increament the cost
				cost++;
			}
		}
		//Reset found to false
		found = false;
	}
	//Return the cost of the partition
	return cost;
}

/*------------------------------------------------------------------------------
Class Function:	setIE_Cost (class Partition)
Input(s):		None
Output:			void (None)
Definition:		Sets the internal and external costs of the nodes in the
	partition. Then calculates and sets the D value of the nodes.
------------------------------------------------------------------------------*/
void Partition::setIE_Cost()
{
	//Declare local variables
	int iCost;
	int eCost;
	bool iConn;

	//Loop through the set of nodes in the partition
	for (int i = 0; i < nodeNum; i++) {
		//Set the costs to zero
		iCost = 0;
		eCost = 0;

		//Set boolean variables
		iConn = false;

		//Loop through the current ID's shared connection list
		for (int j = 0; j < nodes[i].getDegree(); j++) {

			//Loop through the set of nodes in the partition
			for (int k = 0; k < nodeNum; k++) {

				//Check if other node's ID is equal to the connection ID
				if (nodes[i].getConnection(j) == nodes[k].getNodeID()) {
					//Set the internal connection to true
					iConn = true;
				}
			}
			//Check if it was an internal connection
			if (iConn) {
				//Increment the internal cost
				iCost++;

				//Set internal connection to false
				iConn = false;
			}
			//Otherwise it's an external connection
			else {
				//Increment the external cost
				eCost++;
			}
		}
		//Set the internal & external cost for the current node
		nodes[i].setIE(iCost, eCost);

		//Calculate the D value of the current node
		nodes[i].setD();
	}
}

/*------------------------------------------------------------------------------
Class Function:	getD_Value (class Partition)
Input(s):		int id - Node's id
Output:			int - D value for the node
Definition:		Obtains the D value from the node
------------------------------------------------------------------------------*/
int Partition::getD_Value(int id)
{

	//Loop through the nodes in the partition
	for (int i = 0; i < nodeNum; i++) {
		
		//Check if the current node matches the id
		if (id == nodes[i].getNodeID()) {
			//Return the node's D value
			return nodes[i].getD();
		}
	}

	//Return zero on falure
	return 0;
}

/*------------------------------------------------------------------------------
Class Function:	getNodeID (class Partition)
Input(s):		int i - Index into the node array
Output:			int - The id of the node
Definition:		Obtains the D value from the node
------------------------------------------------------------------------------*/
int Partition::getNodeID(int i)
{
	//Return the node's ID
	return nodes[i].getNodeID();
}

/*------------------------------------------------------------------------------
Class Function:	sharedEdge (class Partition)
Input(s):		int id1 - The ID of the node
				int id2 - The ID of the node
Output:			int - Edge shared
Definition:		Returns 1 if the nodes share an edge & returns 0 if nodes don't
	share an edge.
------------------------------------------------------------------------------*/
int Partition::sharedEdge(int id1, int id2)
{
	//Loop through the nodes in the partition
	for (int i = 0; i < nodeNum; i++) {
		
		//Check if the current node matches the id
		if (id1 == nodes[i].getNodeID()) {
			
			//Loop through the connection list of the current node
			for (int j = 0; j < nodes[i].getDegree(); j++) {
				
				//Check if the nodes share an edge
				if (id2 == nodes[i].getConnection(j)) {
					//Edge is shared return one
					return 1;
				}
			}
		}
	}
	//Edge not shared return zero
	return 0;
}

/*------------------------------------------------------------------------------
Class Function:	readNode (class Partition)
Input(s):		int id - ID of the node
Output:			Node - Node object from the partition
Definition:		Returns the node being looked for.
------------------------------------------------------------------------------*/
Node Partition::readNode(int id)
{
	//Loop through the nodes in the partition
	for (int i = 0; i < nodeNum; i++) {

		//Check if the current node matches the id
		if (id == nodes[i].getNodeID()) {
			//Return the node's D value
			return nodes[i];
		}
	}
}

/*------------------------------------------------------------------------------
Class Function:	writeNode (class Partition)
Input(s):		Node toWrite - Node being written to partion
				int id - ID of the node being overwitten
Output:			void (none)
Definition:		Overwrites a node in the partiton and sets the swapped value to
	true.
------------------------------------------------------------------------------*/
void Partition::writeNode(int id, Node toWrite)
{
	//Loop through the nodes in the partition
	for (int i = 0; i < nodeNum; i++) {

		//Check if the current node matches the id
		if (id == nodes[i].getNodeID()) {
			//Write the node to the indexed spot
			nodes[i] = toWrite;

			//Break the loop
			break;
		}
	}
}

/*------------------------------------------------------------------------------
Class Function:	markSwapped (class Partition)
Input(s):		int id - ID of the node being marked swapped
Output:			void (none)
Definition:		Marks a specified node in the partition as swapped
------------------------------------------------------------------------------*/
void Partition::markSwapped(int id)
{
	//Loop through the nodes in the partition
	for (int i = 0; i < nodeNum; i++) {

		//Check if the current node matches the id
		if (id == nodes[i].getNodeID()) {
			//Write the node to the indexed spot
			nodes[i].mark();

			//Break the loop
			break;
		}
	}
}

/*------------------------------------------------------------------------------
Class Function:	checkSwapped (class Partition)
Input(s):		int i - Index into the node array
Output:			bool - If the node has been swapped
Definition:		Checks if the current indexed node has been swapped
------------------------------------------------------------------------------*/
bool Partition::checkSwapped(int i)
{
	//Return the node's ID
	return nodes[i].getSwapped();
}

/*------------------------------------------------------------------------------
Class Function:	unswappedNode (class Partition)
Input(s):		None
Output:			bool - If the node needs to be swapped
Definition:		Checks if there are nodes in the partition that need to be
	swapped.
------------------------------------------------------------------------------*/
bool Partition::unswappedNode()
{
	//Loop through the nodes in the partition
	for (int i = 0; i < nodeNum; i++) {
		//Check if the current node needs to be swapped
		if (!nodes[i].getSwapped()) {
			//Unswapped node found, so return true
			return true;
		}
	}
	//All nodes have been swapped return false
	return false;
}

/*------------------------------------------------------------------------------
Class Function:	unswapAll (class Partition)
Input(s):		None
Output:			void (None)
Definition:		Unswap all the nodes in the partiton.
------------------------------------------------------------------------------*/
void Partition::unswapAll()
{
	//Loop through the nodes in the partition
	for (int i = 0; i < nodeNum; i++) {
		//Write the node to the indexed spot
		nodes[i].unmark();
	}
}