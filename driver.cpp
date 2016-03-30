//CS261 - Asssignment 1

#include <iostream>
#include "bone.h"
#include "yard.h"
#include "hand.h"
#include "player.h"
#include "game.h"
#include "field.h"

using namespace std;

int main()
{
	Game *game = new Game();
	game->run();

	return 0;
}
