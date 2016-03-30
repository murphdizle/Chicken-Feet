#ifndef PLAYER_H
#define PLAYER_H

#include "bone.h"
#include "hand.h"
#include "yard.h"
#include <iostream>

using namespace std;

class Player
{
public:
	//contructors
	Player();

	//destructor
	~Player();

	//mutator functions
	bool drawBone(Yard * yard);
	bool playBone(int num, Bone*& aBone);
	bool highestDouble(int& pos, Bone*& aBone);
	int getTop(int pos, Bone*& aBone);
	int getBottom(int pos, Bone*& aBone);
	void addBone(Bone* aBone);
	//accessor functions
	void getScore() const;
	void getHand() const;
	void getDraw() const;
	int getSize() const;
private:
	Hand hand;
};

#endif
