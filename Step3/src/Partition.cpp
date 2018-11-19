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
		//Set found equal to false
		found = false;
		
		//Loop through the current ID's shared connection list
		for (int j = 0; j < nodes[i].getDegree(); j++) {

			//Loop through the set of nodes in the partition
			for (int k = 0; k < nodeNum; k++) {

				//Check if other node's ID is equal to the connection ID
				if (nodes[i].getConnection(j) == nodes[k].getNodeID()) {
					//Change found to true
					found = true;
				}
			}
		}
		//Check if match was not found
		if (!found) {
			//Increament the cost
			cost++;
		}

		//Reset found to false
		found = false;
	}
	//Return the cost of the partition
	return cost;
}

/*------------------------------------------------------------------------------
Class Function:	costFunction (class Partition)
Input(s):		None
Output:			int - The cost of the partition
Definition:		Calculates the cost of the partition.
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