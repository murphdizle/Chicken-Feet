#include "Yard.h"


Yard::Yard(int players, int bones):
playerCount(players), boneCount(bones)
{
	for (int i = 0; i <= 9; ++i){
		for (int j = i; j <= 9; ++j){
			Bone newBone(i, j);
			Deck.push_back(&newBone);
		}
	}
}


Yard::~Yard()
{
}
