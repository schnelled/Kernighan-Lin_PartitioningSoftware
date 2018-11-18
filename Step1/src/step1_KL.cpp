#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
#include"Set.h"

using namespace std;

//Function prototyping
void errorHandler(string s, string function, int errorNum);

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
	//Check that there are two arguments (function name & file name)
	if (argc != 2) {
		//Error and tell user how to use the function
		errorHandler("Usage Error: ", argv[0], 1);
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

	//Open the benchmark input file
	file.open(argv[1]);

	//Check if the file opened
	if (file.is_open()) {
		//Display file opened message
		cout << "Successfully opened the benchmark file " << argv[1] << endl;

		//Read each line from the benchmark file to obtain number of nodes and edges
		while (getline(file, line)) {
			if (infoSet == false) {
				//Convert the character to an integer
				totalNodes = (int)line[0];
				totalEdges = (int)line[2];

				//Display the integer
				cout << "There are " << totalNodes - 48 << " nodes in the set" << endl;
				cout << "There are " << totalEdges - 48 << " nodes in the set" << endl;

				//Set node count to true
				infoSet = true;
			}
		}
		//Make sure the set has an even number of nodes
		if (totalNodes%2 != 0) {
			errorHandler("Error: Odd number of nodes in ", argv[1], 3);
		}
		
		//Create two equal partitions
		Set partition_1((totalNodes - 48)/2);
		Set partition_2((totalNodes - 48)/2);

		//Display the sizes of the partitions
		cout << "The size of the 1st partition is: " << partition_1.getSize() << endl;
		cout << "The size of the 2nd partition is: " << partition_2.getSize() << endl;

		//Reset the file pointer
		file.clear();
		file.seekg(0, ios::beg);

		//Read each line from the benchmark file
		while ( getline(file, line)) {
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
	}
	//Otherwise file didn't open
	else {
		//Handle the error of the file not opening
		errorHandler("Error: Couldn't open the file ", argv[1], 2);
	}

	//Close the benchmark input file
	file.close();

	//Prompt user to close program
	cout << "Press any key to exit" << endl;

	//Wait for user to enter key
	getwchar();

	//Successful opperation return zero
	return 0;
}

/*-----------------------------------------------------------------
Function:	errorHandler
Inputs:		string s - The error message
			string function - name of the function
Outputs:	none (void)
Definition:	Handles errors by displaying message to the user &
	exiting the program.
-----------------------------------------------------------------*/
void errorHandler(string s, string function, int errorNum)
{
	//Check if error number is one
	if (errorNum == 1) {
		//Display error message to the user
		cout << s << function << " " << "<BenchmarkFile.txt>" << endl;
	}
	//Check if error number is two
	else if (errorNum == 2) {
		//Display error message to the user
		cout << s << function << endl;
	}
	//Otherwise the error number is three
	else {
		//Display error message to the user
		cout << s << function << endl;
	}

	//Prompt user to press key
	cout << "Press any key to exit" << endl;

	//Wait for user to enter key
	getwchar();

	//Exit the program
	exit(0);
}