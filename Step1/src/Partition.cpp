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
	nodes = new int[nodeNum];
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
void Partition::addNode(int nodeID)
{
	//Add the node to the current index location
	nodes[index] = nodeID;

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
		//Display the current node ID
		cout << nodes[i] << " ";
	}

	//Close the displayed partition
	cout << ")" << endl;
}