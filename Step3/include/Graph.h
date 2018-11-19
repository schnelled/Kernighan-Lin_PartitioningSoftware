#include<fstream>
#include<string>
#include"Partition.h"

using namespace std;

class Graph
{
public:
	Graph();
	~Graph();
	void openBenchmark(char*);
	void closeBenchmark();
	void setGraphInfo(char*);
	void displayInfo();
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
