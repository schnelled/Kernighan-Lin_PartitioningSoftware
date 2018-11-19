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
private:
	int partitionNum;
	int nodeNum;
	int index;
	Node* nodes;
};