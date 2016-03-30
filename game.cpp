// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include "game.h"
#include "yard.h"
#include "player.h"
#include "hand.h"
#include "field.h"

using namespace std;

const int MAXBONES = 7;

Game::Game(): turn(0), nPlayers(0), rounds(1), currTurn(0), doublePlayed(false), doublePlays(0){
}
Game::~Game()
{
	for(auto it = players.begin(); it != players.end(); it++){
		delete *it;
	}
}
int Game::nextTurn(){
	currTurn++;
	currTurn = currTurn % nPlayers;
	return currTurn;
}

void Game::run(){
	char ch;

	cout << "Welcome to Chicken-Feet the game!!" << endl << endl;

	cout << "Please enter the number of players between 2 and 4: ";
	cin >> nPlayers;

	while(nPlayers < 2 || nPlayers > 4)
	{
		cin.clear();
		cin.ignore();
		cout << endl << "Invalid number!  Please enter a number between 2 and 4: ";
		cin >> nPlayers;
	}

	for(int i = 0; i < nPlayers; i++)
	{
		players.push_back(new Player());
	}
	cout << endl << "Creating " << nPlayers << " players and dealing " << MAXBONES << " bones each!" << endl << endl;
	Yard * deck = new Yard(1);
	Field *field = new Field();
	deck->shuffleDeck();
	for(int i=0; i < MAXBONES; i++){
		for(int j = 0; j < nPlayers; j++){
			players.at(j)->drawBone(deck);
		}
	}
	while(!firstMove(field)){
		cout << "No one has a double!" << endl;
		cout << "Everybody draws a bone!" << endl;
		for(int i = 0; i < nPlayers; i++){
			players.at(i)->drawBone(deck);
		}
	}
	do{
		cout << "Player " << getTurn() + 1 << ", it's your turn. Your hand is:" << endl << endl;
		players.at(getTurn())->getHand();
		display();
		cout << endl << "Make a selection from the menu above: ";
		cin >> ch;
		options(ch, deck, field);
		if(toupper(ch) == 'P' || toupper(ch) == 'D')
			nextTurn();
	}while(toupper(ch) != 'Q' || gameOver());
}
int Game::getTurn(){
	return currTurn;
}
void Game::display(){
	cout << "---------------------------" << endl;
	cout << "Press (H) to show hand" << endl;
	cout << "Press (P) to play a Bone" << endl;
	cout << "Press (D) to draw a Bone" << endl;
	cout << "Press (S) to see your Score" << endl;
	cout << "Press (F) to see the field" << endl;
	cout << "Press (Q) to quit" << endl;
	cout << "---------------------------" << endl;
}
void Game::options(char ch, Yard * deck, Field *field){
	switch(toupper(ch)){
		case 'H':
			cout << endl << "Bones in hand of player " << currTurn + 1 << " are:" << endl << endl;		 
			players.at(currTurn)->getHand();
			break;
		case 'P':
			gamePlay(field);
			break;
		case 'D':
			cout << "you drew a ";
			players.at(currTurn)->drawBone(deck);
			players.at(currTurn)->getDraw();
			break;
		case 'S':
			//cout << "your current score is " << endl;
			players.at(currTurn)->getScore();
			break;
		case 'F':
			field->print();
			break;
		case 'Q':
			cout << "Thank you for playing!" << endl;
			break;
		default:
			cout << endl << "Please enter a valid command." << endl <<  endl;
	}
}
void Game::gamePlay(Field * field)
{
	int domino, side;
	Bone* aBone = new Bone();
	if(doublePlayed)
	{
		cout << "The last domino played was a double, the only available move is: " 
			 << doubleValue
			 << endl;	
	}
	else
	{
		field->print();	
	}
	cout << "Enter domino you would like to play." << endl;
	cin >> domino;
	cout << "Enter 1 for left and 2 for right" << endl;
	if(cin >> side){}
	else{
		cin.clear();
		cin.ignore();
	}
	if(domino > players.at(currTurn)->getSize() || domino < 1)
	{
		cout << "Domino entered is out of range. Please try again.";
		currTurn = (currTurn - 1) % nPlayers;//it should still be their turn
	}
	else 
	{
		players.at(currTurn)->playBone((domino-1), aBone);
		if(findMove(side, aBone, field))
		{
			field->addBone(aBone);
		}
		else
		{
			players.at(currTurn)->addBone(aBone);			
			currTurn = (currTurn-1)%nPlayers;
			cout << "invalid move" << endl;
		}
	}
	gameOver();

}

bool Game::findMove(int side, Bone* aBone, Field *field) 
{
	Bone *fieldBone = new Bone();
	int pos = 0;
	while(field->eachBone(pos, fieldBone)) //this will loop through the field and end when it's out of range. 
	{
		//double play
		if(doublePlayed)
		{
			if(side == 1) //if they want to play the top
			{
				if(aBone->getTop() != doubleValue)//the bone played does not match the double
					return false;
				//find the double that is being played off of
				if(fieldBone->getIsDouble() && (fieldBone->getTop() == doubleValue))
				{
					if(doublePlays <= 1) //check to see if it's the last side of the double
					{
						doublePlayed = false;
						fieldBone->setBottomUsed(true);
						fieldBone->setTopUsed(true);
					}
					aBone->setTopUsed(true); //set the side of the bone played
					doublePlays--;
					return true;
				}
			}
			if(side == 2)//if they play the bottom 
			{
				if(aBone->getBottom() != doubleValue)
					return false;
				if(fieldBone->getIsDouble() && (fieldBone->getTop() == doubleValue))
				{
					if(doublePlays <= 1)
					{
						doublePlayed = false;
						fieldBone->setBottomUsed(true);
						fieldBone->setTopUsed(true);
					}
					aBone->setBottomUsed(true);
					doublePlays--;
					return true;
				}
			}
		}
		//not a double, should this be in an else?
		if(side==1)
		{
			if((fieldBone->getTop() == aBone->getTop()) && !fieldBone->getTopUsed()) 
			{
				fieldBone->setTopUsed(true);
				aBone->setTopUsed(true);
				if(aBone->getIsDouble())
					setForDouble(aBone);
				return true;
			}
			else if((fieldBone->getBottom() == aBone->getTop()) && !fieldBone->getBottomUsed())
			{
				fieldBone->setBottomUsed(true);
				aBone->setTopUsed(true);
				if(aBone->getIsDouble())
					setForDouble(aBone);
				return true;
			}
		}
		if(side == 2)
		{
			if((fieldBone->getBottom() == aBone->getBottom()) && !fieldBone->getBottomUsed())
			{
				fieldBone->setBottomUsed(true);
				aBone->setBottomUsed(true);
				if(aBone->getIsDouble())
					setForDouble(aBone);
				return true;
			}
			else if((fieldBone->getTop() == aBone->getBottom()) && !fieldBone->getTopUsed())
			{
				fieldBone->setTopUsed(true);
				aBone->setBottomUsed(true);
				if(aBone->getIsDouble())
					setForDouble(aBone);
				return true;
			}
		}
		pos++;//controls the loop
	}
	return false;
}
void Game::setForDouble(Bone*& aBone)
{
	doublePlayed = true;
	doubleValue = aBone->getTop();
	doublePlays = 3;
	aBone->setTopUsed(false);
	aBone->setBottomUsed(false);
}
bool Game::firstMove(Field *field)
{
	Bone *highestBone = new Bone();
	Bone *aBone = new Bone();
	int highest = -1, player, pos = 0, highestPos = 0;
	for(int i=0; i < nPlayers; i++) //begin the game with highest double
	{
		if(players.at(i)->highestDouble(pos, aBone))
		{
			if(highest < aBone->getTop())
			{
				highest = aBone->getTop();
				player = i;
				highestBone = aBone;
				highestPos = pos;
			}
		}
	}
	if(highest < -1)
		return false;
	cout << "Player " 
 		 << player+1
		 << " had the highest double. Bone";
		 highestBone->print();
	cout << "was automatically played." << endl;

	players.at(player)->playBone(highestPos, highestBone);
	field->addBone(highestBone);
	currTurn = (player + 1)% nPlayers;
	doublePlayed = true;
	doublePlays = 3;
	doubleValue = highest;
	cout << endl << "Player " << player + 1 << ", your hand is now:" << endl << endl;
	players.at(player)->getHand();
	return true;
}
bool Game::gameOver()
{
	if(players.at(currTurn)->getSize() < 1)
	{
		cout << "Player " 
		<< currTurn+1
		<< " has won!"
		<< endl;
		return true;
	}
	else 
		return false;
}




