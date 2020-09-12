#include <stdio.h>
#include <iostream>
#include "Controller.h"
#include "Grid.h"
#include "Render.h"
#include "Input.h"
#include "Player.h"
#include <map>
#include <memory>

int main()
{
	
	Controller new_game{};
	new_game.start_game();

	return 0;
}
