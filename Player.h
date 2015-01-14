#pragma once

#include <iostream>
#include "Yard.h"
#include "Bone.h"
#include <vector>

using namespace std;
class Player
{
public:
	Player();
	~Player();

	bool drawCard(Yard* yard);
	bool playBone(Bone* &aBone);
	int getScore(){
		return currScore;
	}
	void setCurrScore(int newScore);
	void print();


private:

	//instance of hand class goes here
	int currScore;

};

