#include <iostream>
#include <vector>
#include "hand.h"

using namespace std;

//constructor/destructor
Hand::Hand() : handScore(0){}

Hand::~Hand()
{
	for (auto it = hand.begin(); it != hand.end(); it++)
	{
		delete *it;
	}
}

//mutator functions
void Hand::addBone(Bone* aBone)
{
	hand.push_back(aBone);

	int top = aBone->getTop();
	int bottom = aBone->getBottom();

	handScore += top + bottom;
}
int Hand::getTop(unsigned int pos, Bone*& aBone){
	if(pos < 0 || pos >= hand.size())
		return false;
	aBone = hand.at(pos);
	return aBone->getTop();
}
int Hand::getBottom(unsigned int pos, Bone*& aBone){
	if(pos < 0 || pos >= hand.size())
		return false;
	aBone = hand.at(pos);
	return aBone->getBottom();
}
int Hand::size() const
{
	return hand.size();
}
bool Hand::removeBone(unsigned int pos, Bone*& aBone)
{
	if (pos < 0 || pos >= hand.size())
		return false;
	aBone = hand.at(pos);
	hand.erase(hand.begin() + pos);

	int top = aBone->getTop();
	int bottom = aBone->getBottom();

	handScore -= top + bottom;

	return true;	 
}
bool Hand::highestDouble(int& pos, Bone*& aBone) 
{
	int highest = -1, highestPos = 0;
	pos = 0;
	for (auto it = hand.begin(); it != hand.end(); it++) 
	{
		if ((*it)->getTop() == (*it)->getBottom())
		{
			if ((*it)->getTop() > highest)
			{
				highest = (*it)->getTop();
				aBone = (*it);
				pos = highestPos;
			}
		}
		highestPos++;
	}
	if(highest > -1)
		return true;
	else
		return false;

}
//accessor function
int Hand::getHandScore() const
{
	return handScore;
}

void Hand::print() const
{
	int dominoNumber = 1;
	for (auto it = hand.cbegin(); it != hand.cend(); it++)
	{
		cout << dominoNumber << " - ";
		(*it)->print();
		cout << endl;
		dominoNumber++;
	}
}
void Hand::printBone() const
{
	auto it = hand.rbegin();
	(*it)->print();
}
