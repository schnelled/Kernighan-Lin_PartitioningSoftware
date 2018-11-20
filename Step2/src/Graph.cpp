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
	interation = 1;
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
		cout << "Successfully opened the benchmark file " << fileName << endl;
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
	for (int i = 0; i < line.size(); i++) {
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
	for (int i = 0; i < line.size(); i++) {
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
Class Function:	displayInfo (class Graph)
Input(s):		None
Output:			void (None)
Definition:		Displays the current interation number & nodes in each
	partition.
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
	cout << "Cost of the partition = " << partition_1->costFunction() << endl;
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
		for (int i = 0; i < line.size(); i++) {
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
		for (int i = 0; i < line.size(); i++) {
			if(line[i] != '\t') {
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
		if (lineIndex == totalNodes/2) {
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
			partition_2->setNodeDegree(lineIndex - (totalNodes/2), degreeCount, temp);
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