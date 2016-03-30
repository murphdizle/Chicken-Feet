#ifndef FIELD_H
#define FIELD_H

#include "bone.h"
#include <vector>
#include <iostream>

using namespace std;

class Field
{
public:

	//constructors
	Field();

	//destructor
	~Field();

	//mutator functions
	void addBone(Bone* aBone);

	//accessor function
	void print() const;
	bool eachBone(unsigned int pos, Bone*& aBone);
private:
	vector<Bone*> field;
	
};

#endif
