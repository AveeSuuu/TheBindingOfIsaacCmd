#include "classes.h"

bool Game::getGameStatus() {
	return gameStatus;
}

Vector2D& Game::getPlayerPos() {

	return player.getPlayerPos();
}

void Game::initGame(int roomX, int roomY) {

	player.setPlayerPos(5, 4);

	setRoomPosition(roomX, roomY);
	changeRoom();

	gameStatus = true;
}

void Game::changeRoom() {

	std::string roomFile;
	setRoomFile(roomFile);
	currentRoom.readRoomFromFile(roomFile);
	currentRoom.setRoomElement(player.getPlayerPos(), enumPlayer);
}

void Game::setRoomPosition(int roomX, int roomY) {

	this->roomPosition.x = roomX;
	this->roomPosition.y = roomY;
}

void Game::setRoomFile(std::string& fileName) {

	fileName += "stage1/"
		+ std::to_string(this->roomPosition.y) 
		+ std::to_string(this->roomPosition.x) 
		+ ".txt";
}

void Game::update() {
	Render render;
	currentRoom.setRoomElement(player.getPlayerPos(), enumPlayer);
	render.renderRoom(currentRoom);
	currentRoom.refreshRoom();
}

void Game::objectInteraction(int keyValue) {

	Movement movement;
	Vector2D predictedObjectPos(player.getPlayerPos());

	movement.move(predictedObjectPos, keyValue);

	if (movement.isPath(predictedObjectPos, currentRoom)) {
		movement.move(player.getPlayerPos(), keyValue);
	}

	if (movement.isDoor(predictedObjectPos, currentRoom)) {
		
		updatePlayerAndRoomPosition(keyValue);
		changeRoom();
	}
}

void Game::updatePlayerAndRoomPosition(int keyValue) {

	switch (keyValue) {
	case moveUp:
		player.setPlayerPos(5, 7);
		roomPosition.moveY(-1);
		break;
	case moveDown:
		player.setPlayerPos(5, 1);
		roomPosition.moveY(1);
		break;
	case moveLeft:
		player.setPlayerPos(9, 4);
		roomPosition.moveX(-1);
		break;
	case moveRight:
		player.setPlayerPos(1, 4);
		roomPosition.moveX(1);
	}
}