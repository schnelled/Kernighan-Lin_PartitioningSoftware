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

	//Open the benchmark file
	G.openBenchmark(argv[1]);

	//Obtain the total number of nodes & edges in the graph
	G.setGraphInfo(argv[1]);

	//Add nodes to the partition
	G.addNodes();

	//Add the degree and adjacent edge information to the node
	G.addNodeInfo();

	//Display the initial setup information
	G.displayInfo();

	//Close the benchmark file
	G.closeBenchmark();

	//Freeze the console
	G.consoleFreeze();

	//Successful opperation return zero
	return 0;
}