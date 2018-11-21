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
	void setIE(int, int);
	void setD();
	int getD();
	void mark();
	void unmark();
	bool getSwapped();

private:
	int id;
	int degrees;
	int* connections;
	int partition;
	int I;
	int E;
	int D;
	bool swapped;
};