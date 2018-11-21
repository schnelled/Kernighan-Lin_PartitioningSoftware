#include<iostream>
#include"Node.h"

using namespace std;

class Partition
{
public:
	Partition(int, int);
	Partition(int, int, Node*);
	~Partition();
	void addNode(int, int);
	void displayNodes();
	void setNodeDegree(int, int, int*);
	int costFunction();
	void setIE_Cost();
	int getD_Value(int);
	int getNodeID(int);
	int sharedEdge(int, int);
	Node readNode(int);
	void writeNode(int, Node);
	void markSwapped(int);
	bool checkSwapped(int);
	bool unswappedNode();
	void unswapAll();
	
private:
	int partitionNum;
	int nodeNum;
	int index;
	Node* nodes;
};