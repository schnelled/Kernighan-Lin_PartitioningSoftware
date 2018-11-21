#include<cstdlib>
#include<string>
#include<iostream>
#include<new>
#include"Graph.h"

using namespace std;

//Default constructor
Graph::Graph()
{
	//Initialize the interation number
	interation = 0;
}

//Deconstructor
Graph::~Graph()
{
	//Delete the partitions
	delete partition_1;
	delete partition_2;
}

/*-------------------------------------------------------------------------
Class Function:	openBenchmark (class Graph)
Input(s):		char* fileName - Name of the file benchmark file
Output:			void (None)
Definition:		Opens the benchmark file.
-------------------------------------------------------------------------*/
void Graph::openBenchmark(char* fileName)
{
	//Open the benchmark file
	file.open(fileName);

	//Check if the file opened
	if (file.is_open()) {
		//Display file opened message
		cout << "Successfully opened the benchmark file " << fileName << endl << endl;
	}
	//Otherwise file didn't open
	else {
		//Handle the error of the file not opening
		errorHandler(1, fileName);
	}
}

/*-------------------------------------------------------------------------
Class Function:	closeBenchmark (class Graph)
Input(s):		None
Output:			void (None)
Definition:		Closes the benchmark file.
-------------------------------------------------------------------------*/
void Graph::closeBenchmark()
{
	//Close the benchmark file
	file.close();
}

/*-------------------------------------------------------------------------
Class Function:	setGraphInfo (class Graph)
Input(s):		None
Output:			void (None)
Definition:		Sets the private variables for the total number of nodes
	& edges in the graph. Also checks if the graph has an even number of
	nodes and setup partitions.
-------------------------------------------------------------------------*/
void Graph::setGraphInfo(char* arg)
{
	//Declare local variables
	int* tempNodeArray;
	int* tempEdgeArray;
	int nodeLength = 0;
	int edgeLength = 0;
	int index = 0;
	int counter;
	bool nodeOrEdge = true;

	//Read the first line of the benchmark file
	getline(file, line);

	//Add new line character to line
	line += '\n';

	//Loop through the line and count
	for (unsigned int i = 0; i < line.size(); i++) {
		//Check if the current character is a digit
		if (isdigit(line[i])) {
			//Check if node
			if (nodeOrEdge) {
				//Increament the node length
				nodeLength++;
			}
			//Otherwise edge
			else {
				//Increment the edge length
				edgeLength++;
			}
		}
		else {
			//Negate the node or edge
			nodeOrEdge = !nodeOrEdge;
		}
	}

	//Initialize the dynamic arrays
	tempNodeArray = new int[nodeLength];
	tempEdgeArray = new int[edgeLength];

	//Loop through the line and add to array
	for (unsigned int i = 0; i < line.size(); i++) {
		//Check if the current character is a digit
		if (isdigit(line[i])) {
			//Check if node
			if (nodeOrEdge) {
				//Add number to node array
				tempNodeArray[index] = (int)line[i] - 48;

				//Increament the index
				index++;
			}
			//Otherwise edge
			else {
				//Add number to edge array
				tempEdgeArray[index] = (int)line[i] - 48;

				//Increament the index
				index++;
			}
		}
		else {
			//Reset the index
			index = 0;

			//Negate the node or edge
			nodeOrEdge = !nodeOrEdge;
		}
	}

	//Set counter
	counter = 0;

	//Loop throught the tempNodeArray
	for(int i = nodeLength - 1; i >= 0; i--) {
		//Check if counter is equal to zero
		if (counter == 0) {
			//Update the total number of nodes in the graph
			totalNodes = tempNodeArray[counter];

			//Increament the counter
			counter++;
		}
		else {
			//Check if current number is zero
			if (tempNodeArray[counter] == 0) {
				//Update the total number of nodes in the graph
				totalNodes = totalNodes * (10 * counter);
			}
			else {
				//Update the total number of nodes in the graph
				totalNodes = totalNodes + tempNodeArray[counter] * (10 * counter);
			}

			//Increament the counter
			counter++;
		}
	}

	//Set counter
	counter = 0;

	//Loop through the tempEdgeArray
	for (int i = edgeLength - 1; i >= 0; i--) {
		//Check if counter is equal to zero
		if (counter == 0) {
			//Update the total number of nodes in the graph
			totalEdges = tempEdgeArray[counter];

			//Increament the counter
			counter++;
		}
		else {
			//Check if current number is zero
			if (tempEdgeArray[counter] == 0) {
				//Update the total number of nodes in the graph
				totalEdges = totalEdges * (10 * counter);
			}
			else {
				//Update the total number of nodes in the graph
				totalEdges = totalEdges + tempEdgeArray[counter] * (10 * counter);
			}

			//Increament the counter
			counter++;
		}
	}

	//Make sure the set has an even number of nodes
	if (totalNodes % 2 != 0) {
		errorHandler(2, arg);
	}

	//Free the memory from the temp arrays
	delete[] tempEdgeArray;
	delete[] tempNodeArray;

	//Declare partition one & partition two
	partition_1 = new Partition(totalNodes / 2, 1);
	partition_2 = new Partition(totalNodes / 2, 2);
}

/*-------------------------------------------------------------------------
Class Function:	displayStart (class Graph)
Input(s):		None
Output:			void (None)
Definition:		Displays the starting partition and the initial cost to
	the user.
-------------------------------------------------------------------------*/
void Graph::displayStart()
{
	//Display the starting partion
	cout << "The starting partition is: " << endl;

	//Display the nodes in partition one
	partition_1->displayNodes();

	//Display the nodes in partition two
	partition_2->displayNodes();

	//Display the cost of the partition
	cout << "Cost of the partition = " << partition_1->costFunction() << endl << endl;
}

/*-------------------------------------------------------------------------
Class Function:	displayInfo (class Graph)
Input(s):		None
Output:			void (None)
Definition:		Displays the current interation number, the nodes in each
	partition, and the cost of the interation to the user.
-------------------------------------------------------------------------*/
void Graph::displayInfo()
{
	//Display the interation number
	cout << "Interation " << interation << endl;

	//Display the nodes in partition one
	partition_1->displayNodes();

	//Display the nodes in partition two
	partition_2->displayNodes();

	//Display the cost of the partition
	cout << "Cost of the partition = " << partition_1->costFunction() << endl << endl;
}

/*-------------------------------------------------------------------------
Class Function:	displayFinal (class Graph)
Input(s):		None
Output:			void (None)
Definition:		Displays the final partition (results) and 
	cost of the partition to the user.
-------------------------------------------------------------------------*/
void Graph::displayFinal()
{
	//Check if iteration is equal to one
	if (interation == 1) {
		//Display the interation number
		cout << "Final partition after " << interation << " interation" << endl;
	}
	else {
		//Display the interation number
		cout << "Final partition after " << interation << " interations" << endl;
	}

	//Display the nodes in partition one
	partition_1->displayNodes();

	//Display the nodes in partition two
	partition_2->displayNodes();

	//Display the cost of the partition
	cout << "Cost of the final partition = " << partition_1->costFunction() << endl;
}

/*-------------------------------------------------------------------------
Class Function:	calcInteration (class Graph)
Input(s):		None
Output:			void (None)
Definition:		Calculates the interation and displays largest gains from
	each swap.
-------------------------------------------------------------------------*/
void Graph::calcInteration()
{
	//Declare local variables
	int D1, D2;
	int ID1, ID2;
	int swap1, swap2;
	int shared;
	int gain;
	int maxGain;
	bool first = true;
	Node tempNode1;
	Node tempNode2;
	K k;
	int kIndex = 0;
	bool nextInteration = true;
	bool best = false;
	int sum;
	int maxSum;
	int maxPosition;

	//Setup and allocate memory for the k structure
	k.gains = (int*)malloc(sizeof(int) * (totalNodes / 2));
	k.P1_IDs = (int*)malloc(sizeof(int) * (totalNodes / 2));
	k.P2_IDs = (int*)malloc(sizeof(int) * (totalNodes / 2));

	//Calculate the internal & external cost of each node
	partition_1->setIE_Cost();
	partition_2->setIE_Cost();

	while (nextInteration == true) {

		/*--------------------------------KL Algorithm Start-------------------------------*/
		//Loop while there are unswapped nodes
		while (partition_1->unswappedNode()) {

			/*-------------------------Check nodes from partition one----------------------*/
			//Loop through partition one to obtain IDs
			for (int i = 0; i < (totalNodes / 2); i++) {

				//Check if not swapped
				if (!partition_1->checkSwapped(i)) {

					//Obtain the current node ID from partition one
					ID1 = partition_1->getNodeID(i);

					//Obtain the D value of the node from partition one
					D1 = partition_1->getD_Value(ID1);

					/*-------------------Check nodes from partition two-------------------*/
					//Loop through partition two to obtain IDs
					for (int j = 0; j < (totalNodes / 2); j++) {

						//Check if not swapped
						if (!partition_2->checkSwapped(j)) {

							//Obtain the current node ID from partition two
							ID2 = partition_2->getNodeID(j);

							//Obtain the D value of the node from partition two
							D2 = partition_2->getD_Value(ID2);

							//Check to see if the nodes share an edge
							shared = partition_1->sharedEdge(ID1, ID2);

							/*-------------------Calculate the value of Gij--------------------*/
							//Check if this is the first time through the interation
							if (first) {
								//Caclulate the gain
								gain = D1 + D2 - (2 * shared);

								//Set the value of max gain
								maxGain = gain;

								//Set first equal to false
								first = false;

								//Set the swap IDs
								swap1 = ID1;
								swap2 = ID2;
							}
							/*-------------------Calculate the value of Gij--------------------*/
							else
							{
								//Caclulate the gain
								gain = D1 + D2 - (2 * shared);

								//Check if the new gain is better
								if (gain > maxGain) {
									//Set the value of max gain
									maxGain = gain;

									//Set the swap IDs
									swap1 = ID1;
									swap2 = ID2;
								}
							}
						}
					}
				}
			}
			/*-----------------------All nodes checked for Gij-------------------------*/
			//Mark nodes as swapped
			partition_1->markSwapped(swap1);
			partition_2->markSwapped(swap2);

			//Set the k values for the interation
			k.gains[kIndex] = maxGain;
			k.P1_IDs[kIndex] = swap1;
			k.P2_IDs[kIndex] = swap2;

			//Increment the index for the k structure
			kIndex++;

			//Obtain nodes from partition one and partition two
			tempNode1 = partition_1->readNode(swap1);
			tempNode2 = partition_2->readNode(swap2);

			//Swap the two nodes
			partition_1->writeNode(swap1, tempNode2);
			partition_2->writeNode(swap2, tempNode1);

			//Calculate the new D values
			partition_1->setIE_Cost();
			partition_2->setIE_Cost();

			//Set first to true
			first = true;
		}
		//Set values equal to zero
		sum = 0;
		maxSum = 0;
		maxPosition = 0;

		//Set best to true
		best = true;

		//Calculate the best move
		for (int i = 0; i < kIndex; i++) {
			//Set the value of some
			sum += k.gains[i];

			//Check if the sum is greater than zero
			if (sum >= 1) {
				//Check if this is the first time being greater than zero
				if (first) {
					//Maintain the maximum sum and its position
					maxSum = sum;
					maxPosition = i;

					//Set best to false
					best = false;

					//Set first to false
					first = false;

					//Set nextInteration to true
					nextInteration = true;
				}
				else {
					//Check if the current sum is greater than max sum
					if (sum > maxSum) {
						//Maintain the maximum sum and its position
						maxSum = sum;
						maxPosition = i;
					}
				}
			}
			if (best) {
				//Set next interation to false
				nextInteration = false;
			}
		}

		//Check if this is the best partition
		if (!best) {

			//Loop to swap the nessecary nodes
			for (int i = 0; i <= maxPosition; i++) {
				//Obtain nodes from partition one and partition two
				tempNode1 = partition_2->readNode(k.P1_IDs[i]);
				tempNode2 = partition_1->readNode(k.P2_IDs[i]);

				//Swap the two nodes
				partition_2->writeNode(k.P1_IDs[i], tempNode2);
				partition_1->writeNode(k.P2_IDs[i], tempNode1);

			}
			//Set all the nodes to unswapped
			partition_1->unswapAll();
			partition_2->unswapAll();

			//Calculate the new D values
			partition_1->setIE_Cost();
			partition_2->setIE_Cost();

			//Increment the interation number
			interation++;

			//Display the nodes
			displayInfo();
		}
		else {
			//Increment the interation number
			interation++;

			//Display final
			displayFinal();
		}

		//Set first to true
		first = true;

		//Reset the value of k index
		kIndex = 0;
	}
	//Free the memory for the k structure
	free(k.gains);
	free(k.P1_IDs);
	free(k.P2_IDs);
}

/*-------------------------------------------------------------------------
Class Function:	addNodes (class Graph)
Input(s):		None
Output:			void (None)
Definition:		Adds nodes the partitions in the graph.
-------------------------------------------------------------------------*/
void Graph::addNodes()
{
	//Add node ID's to partition one & partition two
	for (int i = 1; i <= (totalNodes / 2); i++) {
		partition_1->addNode(i, 1);
		partition_2->addNode(i + (totalNodes / 2), 2);
	}
}

/*-------------------------------------------------------------------------
Class Function:	addNodeInfo (class Graph)
Input(s):		None
Output:			void (None)
Definition:		Read the benchmark file for information about the node's 
	adjacent connections and number of degrees, so they can be added to
	the node object
-------------------------------------------------------------------------*/
void Graph::addNodeInfo()
{
	//Declare local variables
	int degreeCount = 0;
	int lineIndex = 0;
	int intIndex = 0;
	bool partition1 = true;
	int position1 = 0;
	int position2 = position1;
	int currentDigit;
	int multiplier;
	int subMult;
	int* temp;

	//Read each line of the benchmark file
	while (getline(file, line)) {
		//Add new line to current line
		line += '\n';

		//Loop through the line and count the number of adjacent edges
		for (unsigned int i = 0; i < line.size(); i++) {
			//Check if the current character is a digit
			if (!isdigit(line[i])) {

				//Check to make sure current character isn't a tab
				if (line[i] != '\t') {
					//Increament the degree count for the current node
					degreeCount++;
				}
			}
		}

		//Allocate memory to the temp array of connections
		temp = new int[degreeCount];

		//Loop through the line and count the number of adjacent edges
		for (unsigned int i = 0; i < line.size(); i++) {
			if (line[i] != '\t') {
				//Check if the current character is a digit
				if (isdigit(line[i])) {
					//Increment position one
					position1++;
				}
				//Otherwise on a digit
				else {
					//Calculate the length of the current digit
					multiplier = position1 - position2;

					//Calculate the subMult
					subMult = multiplier - 1;

					//Set current digit to zero
					currentDigit = 0;

					//Loop to obtain the digit
					for (int j = position2; j < position1; j++) {
						//Check if the multiplier is equal to zero
						if (subMult == 0) {
							//Obtain the current digit
							currentDigit = (int)line[j] - 48;
						}
						else {
							//Check if last digit
							if (j + 1 == position1) {
								//Add the current digit
								currentDigit = currentDigit + ((int)line[j] - 48);
							}
							else {
								//Add the current digit
								currentDigit = currentDigit + ((int)line[j] - 48) * (10 * (multiplier - subMult));
							}
						}
						//Increment subMult
						subMult++;
					}
					//Add the connection value to the temp array
					temp[intIndex] = currentDigit;

					//Increament the integer index
					intIndex++;

					//Increment position one
					position1++;

					//Set position two equal to position one
					position2 = position1;
				}
			}
		}

		//Check the partition of the node
		if (lineIndex == totalNodes / 2) {
			//Negation of halfway complete
			partition1 = !partition1;
		}

		//Check the current partition is one
		if (partition1) {
			//Add degree information to the current node
			partition_1->setNodeDegree(lineIndex, degreeCount, temp);
		}
		//Otherwise it's partition two
		else {
			//Add degree information to the current node
			partition_2->setNodeDegree(lineIndex - (totalNodes / 2), degreeCount, temp);
		}

		//Cleanup counters and local variables
		degreeCount = 0;
		intIndex = 0;
		position1 = 0;
		position2 = position1;
		lineIndex++;

		//Delete the allocated memory
		delete[] temp;
	}
}

/*-------------------------------------------------------------------------
Class Function:	consoleFreeze (class Graph)
Input(s):		None
Output:			void (None)
Definition:		Freezes the consol for the user.
-------------------------------------------------------------------------*/
void Graph::consoleFreeze()
{
	//Prompt user to press key
	cout << "Press any key to exit" << endl;

	//Wait for user to enter key
	getwchar();
}

/*-------------------------------------------------------------------------
Class Function:	errorHandler (class Graph)
Input(s):		int errID - Unique error id number
				char* arg - Error message argument
Output:			void (None)
Definition:		Handles errors for the graph object.
-------------------------------------------------------------------------*/
void Graph::errorHandler(int errID, char* arg)
{
	//Check the error code ID
	switch (errID) {
	case 0:
		//Message to user about function usage
		cout << "Usage Error: " << arg << " <benchmark.txt>" << endl;
		break;
	case 1:
		//Message to user that file didn't open
		cout << "File Error: Couldn't open the file " << arg << endl;
		break;
	case 2:
		//Message to user that graph contains an odd number of nodes
		cout << "Graph Error: Odd number of nodes in " << arg << endl;
		break;
	}

	//Freeze the console
	consoleFreeze();

	//Exit the program
	exit(1);
}