#include<iostream>
#include<fstream>
#include<string>
#include"Graph.h"

using namespace std;

/*-----------------------------------------------------------------
Function:	main
Inputs:		int argc - the number of arguments
			char* argv - charater vector of arguments
Output:		int - return zero upon successful operation
Definition:	Opens the benchmark file specified in the command line
	& stores the information, so the Kernighan-Lin algorithm can
	be preformed.
-----------------------------------------------------------------*/
int main(int argc, char* argv[])
{
	//Initialize a new graph
	Graph G;

	//Check that there are two arguments (function name & file name)
	if (argc != 2) {
		//Error and tell user how to use the function
		G.errorHandler(0, argv[0]);
		//errorHandler("Usage Error: ", argv[0], 1);
	}

	//Declare local variables
	ifstream file;
	string line;
	int currentNum;
	int totalNodes;
	int totalEdges;
	int idNum = 0;
	bool infoSet = false;
	bool firstLine = true;

	//Open the benchmark file
	G.openBenchmark(argv[1]);

	//Obtain the total number of nodes & edges in the graph
	G.setGraphInfo(argv[1]);

	//Add nodes to the partition
	G.addNodes();

	//Display the total number of nodes & edges in the graph
	G.displayInfo();

	//Read each line from the benchmark file
	while (getline(file, line)) {
		//Add newline to current line
		line += '\n';

		//Check if current line is a node
		if (firstLine == false) {
			//Display the unique ID of the current node
			cout << "Node: " << idNum << endl;
		}

		//Loop through the characters in the string
		for (int i = 0; i < line.size(); i++) {
			//Check if current character is a number
			if (isdigit(line[i]) && (firstLine == false)) {
				//Convert the character to an integer
				currentNum = (int)line[i];

				//Display the integer
				cout << currentNum - 48;
			}

			//Check for space character
			if (line[i] == ' ') {
				cout << ' ';
			}

			//Check for newline character
			if (line[i] == '\n') {
				cout << endl;
			}
		}
		//Set the value of first line to false
		firstLine = false;

		//Increment the node ID
		idNum++;
	}

	//Close the benchmark file
	G.closeBenchmark();

	//Freeze the console
	G.consoleFreeze();

	//Successful opperation return zero
	return 0;
}