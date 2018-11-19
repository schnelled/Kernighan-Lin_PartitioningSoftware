using namespace std;

class Node
{
public:
	Node();
	~Node();
	void nodeSetup(int, int);
	int getNodeID();
	void setDegree(int, int*);
	int getConnection(int);
	int getDegree();

private:
	int id;
	int degrees;
	int* connections;
	int partition;
};