#include<iostream>

using namespace std;

class Partition
{
public:
	Partition(int, int);
	~Partition();
	void addNode(int);
	void displayNodes();
private:
	int partitionNum;
	int nodeNum;
	int* nodes;
	int index;
};