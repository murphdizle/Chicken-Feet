#include "bone.h"
#include <iostream>

using namespace std;


Bone::Bone()
{
}

Bone::Bone(int top, int bottom) :
top(top), bottom(bottom), isDouble(false)
{
}

Bone::~Bone()
{
}

int Bone::getTop() const{
	return top;
}

int Bone::getBottom() const{
	return bottom;
}

bool Bone::getIsDouble() const{
	return isDouble;
}

bool Bone::getTopUsed() const{
	return topUsed;
}

bool Bone::getBottomUsed() const{
	return bottomUsed;
}

void Bone::setTop(int newTop){
	top = newTop;
}

void Bone::setBottom(int newBottom){
	bottom = newBottom;
}

void Bone::setIsDouble(bool newBool){
	isDouble = newBool;
}

void Bone::setTopUsed(bool newBool){
	topUsed = newBool;
}

void Bone::setBottomUsed(bool newBool){
	bottomUsed = newBool;
}


void Bone::print() const
{
	cout << " [" << top << "|" << bottom << "] ";
}
