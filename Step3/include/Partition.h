#include<iostream>
#include"Node.h"

using namespace std;

class Partition
{
public:
	Partition(int, int);
	~Partition();
	void addNode(int, int);
	void displayNodes();
	void setNodeDegree(int, int, int*);
	int costFunction();
	void setIE_Cost();
	int getD_Value(int);
	int getNodeID(int);
	int sharedEdge(int, int);
private:
	int partitionNum;
	int nodeNum;
	int index;
	Node* nodes;
};