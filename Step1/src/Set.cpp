#include"Set.h"

//Default constructor for set class
Set::Set(int size)
{
	//Initialize the created set
	setSize = size;
}

//Deconstructor for the set class
Set::~Set()
{
}

int Set::getSize()
{
	//Return the size of the set (partition)
	return setSize;
}