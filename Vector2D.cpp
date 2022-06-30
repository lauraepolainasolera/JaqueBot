#include "Vector2D.h"

Vector2D Vector2D:: operator - (Vector2D v) {
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;

}

bool Vector2D:: operator==(Vector2D v) {
	if (x == v.x && y == v.y) return true;
}