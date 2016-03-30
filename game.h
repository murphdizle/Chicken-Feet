#ifndef GAME_H
#define GAME_H

#include "bone.h"
#include "hand.h"
#include "yard.h"
#include "player.h"
#include "field.h"

#include <iostream>

using namespace std;

class Game{
public:
	Game();

	~Game();

	int nextTurn();
	void run();
	int getTurn();
	void display();
	void options(char ch, Yard * deck, Field *field);
	void setForDouble(Bone*& aBone);
	bool findMove(int side, Bone* aBone, Field *field); 
	void gamePlay(Field *field);
	bool firstMove(Field *field);
	bool gameOver();


private:
	int turn;
	int nPlayers;
	int rounds;
	int currTurn;
	bool doublePlayed;
	int doubleValue;
	int doublePlays;
	bool gameEnd;
	vector<Player*> players;
};

#endif 
