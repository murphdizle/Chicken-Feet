#pragma once
class Bone
{
public:
	Bone();

	Bone(int top, int bottom);
	~Bone();

	//accessor
	int getTop() const{
		return top;
	}

	int getBottom() const{
		return bottom;
	}

	//mutator
	int setTop(int newTop);
	int setBottom(int newBottom);
	bool setIsDouble();
	bool setTopUsed();
	bool setBottomUsed();

private:
	int top;
	int bottom;
	bool isDouble;
	bool topUsed;
	bool bottomUsed;

};
