// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "game.h"
using namespace std;

Game::Game(int nPlayers): players(nPlayers){}

Game::Game(int nPlayers, int nRounds): players(nPlayers), rounds(nRounds){}

int Game::setTurn(int player){
	currTurn = player;
}

void Game::run(){
	//Player::player(n) //this calls the player constructor from Player class and creats n players
}
