#ifndef CLASSES_H_
#define CLASSES_H_

#include <string>
#include <memory>
#include <stdexcept>

#define ROOM_WIDTH 11 //9 playable
#define ROOM_HEIGHT 9 //7 playable

enum ObjectType {
	path, rock, wall, hole, door, enumPlayer
};

enum controlKeys {
	moveUp = 119, moveDown = 115, moveLeft = 97, moveRight = 100
};

class Vector2D {
public:
	int x, y;
	Vector2D();
	Vector2D(int x, int y);
	Vector2D(const Vector2D& other);
	void moveX(int distance);
	void moveY(int distance);
};

class Statistics { 

};

class Player {
private:
	Vector2D playerPos;
public:
	Vector2D& getPlayerPos();
	void setPlayerPos(int x, int y);
	void setPlayerPos(Vector2D& other);
	void movePlayerX(int distance);
	void movePlayerY(int distance);
};

class Room {
private:
	std::string roomFileName;
public:
	ObjectType room[ROOM_HEIGHT][ROOM_WIDTH]{path};
	void readRoomFromFile(std::string fileName);
	void refreshRoom();
	void setRoomElement(const Vector2D& position, ObjectType object);
	ObjectType getRoomElement(int x, int y);
	ObjectType getRoomElement(Vector2D& position);
};

class Render {
public:
	void clearScreen();
	void renderRoom(Room& room);
};

class Converter {
public:
	void fromFileToEnum(ObjectType room[][ROOM_WIDTH], std::string fileName);
	std::string fromEnumToString(ObjectType object);

};

class Stage { 
public:
};

class Menu {
public:
	void menuHeader();
	void selectOptions();
};

class Movement { 
public:
	bool isPath(Vector2D& position, Room& room);
	bool isDoor(Vector2D& position, Room& room);
	void move(Vector2D& position, int inputValue);
};

class UserInput {
private:
	int pressedKeyValue=0;
public:
	void readKeyboard();
	int getPressedKey();
	bool isMovementKey();
};

class Game {
private:
	bool gameStatus = false;
	Vector2D roomPosition;
	Player player;
	Room currentRoom;
public:
	bool getGameStatus();
	Vector2D& getPlayerPos();
	void initGame(int roomX, int roomY);
	void changeRoom();
	void setRoomPosition(int roomX, int roomY);
	void setRoomFile(std::string& fileName);
	void update();
	void objectInteraction(int keyValue);
	void updatePlayerAndRoomPosition(int keyValue);
};

#endif //CLASSES_H_
