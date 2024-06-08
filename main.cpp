#include <iostream>
#include <conio.h>
#include <windows.h>
#include "classes.h"

int main() {

	Game game;
	UserInput input;

	game.initGame(12, 12); //x,y stands for middle of 25x25 array 

	while (game.getGameStatus()) {
		system("CLS");
		game.update();
		input.readKeyboard();
		if (input.isMovementKey()) {
			game.objectInteraction(input.getPressedKey());
		}
	}

	return 0;
}
