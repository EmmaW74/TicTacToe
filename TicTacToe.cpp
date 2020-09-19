#include <stdio.h>
#include <iostream>
#include "Controller.h"
#include "Grid.h"
#include "Render.h"
#include "Input.h"
#include "Player.h"
#include <map>
#include <memory>
#include "BuildGame.h"

int main()
{
	/*
	Controller new_game{};
	new_game.start_game();
	*/

	BuildGame new_game{};
	new_game.create_game();
	return 0;
}
