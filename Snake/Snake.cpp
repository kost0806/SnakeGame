#include "Snake.h"

bool Point::operator== (const Point &a) {
	return this->x == a.x && this->y == a.y;
}

Point Snake::moveTo(Point target, bool eat) {
	this->body.push_front(target);
	if (!eat) {
		Point tail = this->body.back();
		this->body.pop_back();
		return tail;
	}
	return Point(-1, -1);
}

deque<Point>::iterator Snake::getBodyIter() {
	return this->body.begin();
}

Point Snake::head() {
	return this->body.front();
}

Point Snake::tail() {
	return this->body.back();
}

bool Snake::isCrash() {
	deque<Point>::iterator iter = this->body.begin();
	Point head = *iter++;
	for (; iter != this->body.end(); ++iter) {
		if (head == *iter)
			return true;
	}
	return false;
}

int Snake::length() {
	return this->body.size();
}

Point::Point(int x, int y) {
	this->x = x; this->y = y;
}
