#include<iostream>
#include<fstream>
#include<string>
#include<cctype>

using namespace std;

//Function prototyping
void errorHandler(string s, string function);

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
	if (argc != 2)
	{
		//Error and tell user how to use the function
		errorHandler("Usage Error: ", argv[0]);
	}

	//Declare local variables
	ifstream file;
	string line;
	int currentNum;

	//Open the benchmark input file
	file.open(argv[1]);

	//Check if the file opened
	if (file.is_open())
	{
		//Display file opened message
		cout << "Successfully opened the benchmark file " << argv[1] << endl;

		//Read each line from the benchmark file
		while ( getline(file, line))
		{
			//Add newline to current line
			line += '\n';

			//Loop through the characters in the string
			for (int i = 0; i < line.size(); i++)
			{
				//Check if current character is number
				if (isdigit(line[i]))
				{
					//Convert the character to an integer
					currentNum = (int)line[i];

					//Display the integer
					cout << currentNum - 48;
				}
				//Otherwise the it's not an integer
				else
				{
					//Display the current character in the string
					cout << line[i];
				}

				//Check for newline character
				if (line[i] == '\n')
				{
					cout << endl;
				}
			}
		}
	}
	//Otherwise file didn't open
	else
	{
		//Handle the error of the file not opening
		errorHandler("Error: Couldn't open the file ", argv[1]);
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
void errorHandler(string s, string function)
{
	//Display error message to the user
	cout << s << function << " " << "<BenchmarkFile.txt>" << endl;
	cout << "Press any key to exit" << endl;

	//Wait for user to enter key
	getwchar();

	//Exit the program
	exit(0);
}