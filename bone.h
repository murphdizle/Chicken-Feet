#pragma once

#include <iostream>

using namespace std;

class Bone
{
public:
	Bone();

	Bone(int top, int bottom);
	~Bone();

	//accessor
	int    getTop() const;
	int    getBottom() const;
	bool   getIsDouble() const;
	bool   getTopUsed() const;
	bool   getBottomUsed() const;

	//mutator
	void   setTop(int newTop);
	void   setBottom(int newBottom);
	void   setIsDouble(bool);
	void   setTopUsed(bool);
	void   setBottomUsed(bool);

	void print() const;

private:
	int    top;
	int    bottom;
	bool   isDouble;
	bool   topUsed;
	bool   bottomUsed;

};
