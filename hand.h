#ifndef HAND_H
#define HAND_H

#include "bone.h"
#include <vector>
#include <iostream>

using namespace std;

class Hand
{
public:

	//constructors
	Hand();

	//destructor
	~Hand();

	//mutator functions
	void addBone(Bone* aBone);
	bool removeBone(unsigned int pos, Bone*& aBone);
	bool highestDouble(int& pos, Bone*& aBone);
	int getTop(unsigned int pos, Bone*& aBone);
	int getBottom(unsigned int pos, Bone*& aBone);
	//accessor function
	void print() const;
	void printBone() const;
	int getHandScore() const;
	int size() const;
private:
	vector<Bone*> hand;
	int handScore;
	
};

#endif
