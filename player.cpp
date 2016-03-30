#include <iostream>
#include "player.h"
#include "hand.h"

using namespace std;

//constructor / destructor
Player::Player(){}

Player::~Player(){}	

//mutator functions
bool Player::drawBone(Yard * yard)
{
	Bone * aBone;
	bool done = false;

	if (yard->deal(aBone))
	{
		hand.addBone(aBone);
		done = true;
	}
	return done;
}

bool Player::playBone(int num, Bone*& aBone)
{
	return hand.removeBone(num, aBone);
}
void Player::addBone(Bone* aBone)
{
	hand.addBone(aBone);
}
bool Player::highestDouble(int& pos, Bone*& aBone) 
{
	return hand.highestDouble(pos, aBone);
}
int Player::getTop(int pos, Bone*& aBone)
{
	return hand.getTop(pos, aBone);
}
int Player::getBottom(int pos, Bone*& aBone)
{
	return hand.getBottom(pos, aBone);
}
int Player::getSize() const
{
	return hand.size();
}
//accessor functions
void Player::getScore() const
{
	cout << "Player score: " << hand.getHandScore() << endl << endl;
}

void Player::getHand() const
{
	hand.print();
	cout << endl;
}
void Player::getDraw() const
{
	hand.printBone();
	cout << endl;
}
