#include<fstream>
#include<string>
#include"Partition.h"

using namespace std;

struct K {
	int* P1_IDs;
	int* P2_IDs;
	int* gains;
};

class Graph
{
public:
	Graph();
	~Graph();
	void openBenchmark(char*);
	void closeBenchmark();
	void setGraphInfo(char*);
	void displayStart();
	void displayInfo();
	void displayFinal();
	void calcInteration();
	void addNodes();
	void addNodeInfo();
	void consoleFreeze();
	void errorHandler(int, char*);

private:
	ifstream file;
	string line;
	int totalNodes;
	int totalEdges;
	int interation;
	Partition* partition_1;
	Partition* partition_2;
};
