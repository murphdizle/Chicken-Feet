#pragma once

#include <iostream>
#include <vector>
#include "Bone.h"

using namespace std;

class Yard
{
public:
	Yard(int players, int bones);
	~Yard();

	void shuffleDeck();
	bool deal(Bone* &abone);
	void print();
	int getBoneCount() const{
		return boneCount;
	}
	int getPlayerCount() const{
		return playerCount;
	}
	void setBoneCount(int newCount);
	void setPlayerCount(int newCount);
	

private:
	Bone card;
	vector<Bone*> Deck;

	int boneCount; //keep track of available bones in deck
	int playerCount; 
};

