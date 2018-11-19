using namespace std;

class Node
{
public:
	Node();
	~Node();
	void nodeSetup(int, int);
	int getNodeID();
	void setDegree(int, int*);

private:
	unsigned int id;
	unsigned int degrees;
	unsigned int* connections;
	unsigned int partition;
};