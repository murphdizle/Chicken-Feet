#ifndef YARD_H
#define YARD_H

#include <iostream>
#include <vector>
#include "bone.h"

using namespace std;

class Yard
{
public:
	Yard(int players);
	~Yard();

	void shuffleDeck();
	bool deal(Bone* &aBone);
	void print() const;
	int getPlayerCount() const{
		return playerCount;
	}
	bool isEmpty();
	//void setPlayerCount(int newCount);
	
private:
	vector<Bone*> deck;

	int playerCount; 
};

#endif
