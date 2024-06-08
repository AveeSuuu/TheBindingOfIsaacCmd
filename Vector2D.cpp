#include "classes.h"

Vector2D::Vector2D() {
	this->x = 0;
	this->y = 0;
}

Vector2D::Vector2D(int x, int y) {
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D(const Vector2D& other) {

	this->x = other.x;
	this->y = other.y;
}

void Vector2D::moveX(int distance) {
	this->x += distance;
}

void Vector2D::moveY(int distance) {
	this->y += distance;
}