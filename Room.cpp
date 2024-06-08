#include "classes.h"


void Room::readRoomFromFile(std::string fileName) {
	Converter converter;
	roomFileName = fileName;
	converter.fromFileToEnum(this->room, fileName);
}

void Room::refreshRoom() {
	Converter converter;
	converter.fromFileToEnum(this->room, roomFileName);
}

void Room::setRoomElement(const Vector2D& position, ObjectType object) {
	room[position.y][position.x] = object;
}

ObjectType Room::getRoomElement(int x, int y) {
	return room[y][x];
}

ObjectType Room::getRoomElement(Vector2D& position) {
	return room[position.y][position.x];
}