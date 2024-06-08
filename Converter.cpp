#include <fstream>
#include "classes.h"


void Converter::fromFileToEnum(
    ObjectType room[][ROOM_WIDTH], std::string fileName) {

    std::fstream file;
    file.open(fileName);

    if (!file.is_open()) {
        return;
    }

    int x = 0;
    int y = 0;
    char singleChar;
    while (!file.eof()) {
        file >> singleChar;

        switch (singleChar) {
        case 'r':
            room[y][x] = rock;
            x++;
            break;
        case 'p':
            room[y][x] = path;
            x++;
            break;
        case 'w':
            room[y][x] = wall;
            x++;
            break;
        case 'h':
            room[y][x] = hole;
            x++;
            break;
        case 'd':
            room[y][x] = door;
            x++;
            break;
        case ';':
            y++;
            x = 0;
            break;
        }
    }

    file.close();
}

std::string Converter::fromEnumToString(ObjectType object) {

    switch (object) {
    case path: {
        return "   ";
        break;
    }
    case rock: {
        return "[R]";
        break;
    }
    case wall: {
        return "[W]";
        break;
    }
    case hole: {
        return "   ";
        break;
    }
    case door: {
        return "[ ]";
        break;
    }
    case enumPlayer: {
        return "(X)";
        break;
    }
    default:
        return "";
        break;
    }
}
