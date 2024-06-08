#include "classes.h"

bool Movement::isPath(Vector2D& position, Room& room) {

	ObjectType object = room.getRoomElement(position);

	if (object == path) {
		return true;
	}

	return false;
}

bool Movement::isDoor(Vector2D& position, Room& room) {

	ObjectType object = room.getRoomElement(position);

	if (object == door) {
		return true;
	}

	return false;
}

void Movement::move(Vector2D& position, int inputValue) {

	switch (inputValue) {
	case moveUp:
		position.moveY(-1);
		break;
	case moveDown:
		position.moveY(1);
		break;
	case moveLeft:
		position.moveX(-1);
		break;
	case moveRight:
		position.moveX(1);
		break;
	default:
		break;
	}
}
