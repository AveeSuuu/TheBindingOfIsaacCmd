#include <conio.h>
#include "classes.h"

void UserInput::readKeyboard() {

	pressedKeyValue = _getch();
}

int UserInput::getPressedKey() {

	return pressedKeyValue;
}

bool UserInput::isMovementKey() {

	if (pressedKeyValue == moveUp
		|| pressedKeyValue == moveDown
		|| pressedKeyValue == moveLeft
		|| pressedKeyValue == moveRight) {

		return true;
	}

	return false;
}