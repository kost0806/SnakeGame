#include <deque>
#include <iterator>

using namespace std;

class Point {
public:
	int x, y;
	Point(int x, int y);
	bool operator== (const Point &a);
};

class Snake {
private:
	int point;
	deque<Point> body;

public:
	Point moveTo(Point target, bool eat);
	deque<Point>::iterator getBodyIter();
	Point head();
	Point tail();
	bool isCrash();
	int length();
};
