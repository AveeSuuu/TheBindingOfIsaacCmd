#include <iostream>
#include "classes.h"

void Render::clearScreen() {
	std::cout << "\x1B[2J\x1B[H";
}

void Render::renderRoom(Room& room) {

	Converter converter;

	if (true) {
		for (int i = 0; i < ROOM_HEIGHT; i++) {
			for (int j = 0; j < ROOM_WIDTH; j++) {

				std::cout <<
					converter.fromEnumToString(
						room.room[i][j]
					);
			}
			std::cout << std::endl;
		}
	}
}

