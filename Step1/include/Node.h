using namespace std;

//Node class for creating each node in the graph
class Node
{
public:
	Node();
	~Node();
	void setNodeID(int ID);
	void setDegree(int numDegree);
	int getID();
	int getDegree();

private:
	int nodeID;
	int degree;
	int* edges;
};