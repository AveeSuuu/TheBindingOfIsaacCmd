#include "classes.h"

Vector2D& Player::getPlayerPos() {
	return playerPos;
}

void Player::setPlayerPos(int x, int y) {
	playerPos.x = x;
	playerPos.y = y;
}

void Player::setPlayerPos(Vector2D& other) {
	playerPos.x = other.x;
	playerPos.y = other.y;
}

void Player::movePlayerX(int distance) {
	playerPos.x += distance;
}

void Player::movePlayerY(int distance) {
	playerPos.y += distance;
}