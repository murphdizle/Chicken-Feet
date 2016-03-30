#include <iostream>
#include <vector>
#include "field.h"

using namespace std;

//constructor/destructor
Field::Field() {}

Field::~Field()
{
	for (auto it = field.begin(); it != field.end(); it++)
	{
		delete *it;
	}
}

//mutator functions
void Field::addBone(Bone* aBone)
{
	field.push_back(aBone);
}
bool Field::eachBone(unsigned int pos, Bone*& aBone)
{
	cout << "TEST Field.size() " << field.size() << endl;
	if(pos < 0 || pos >= field.size())
		return false;
	aBone = field.at(pos);
	return true;
	
}
//accessor function

void Field::print() const
{
	for (auto it = field.cbegin(); it != field.cend(); it++)
	{
		if(!(*it)->getTopUsed())
			cout << "[" << (*it)->getTop() << "|";
		else 
			cout << "[x|";
		if(!(*it)->getBottomUsed())
			cout << (*it)->getBottom() << "]";
		else 
			cout << "x]";
	}
	cout << endl << endl;
}

