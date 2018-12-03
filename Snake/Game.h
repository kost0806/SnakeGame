#include "Snake.h"
#include "Rander.h"
#include <chrono>

class Game {
private:
	Snake snake;
	int **map;
	int width, height;
	int direction = 3; // UP, DOWN, LEFT, RIGHT
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	DWORD speed;
	DWORD last_update;
	DWORD curr_time;
	Rander rander;
	bool bGameOver = false;
	int last_direction = this->direction;

	void update();
	void setup();
	void nextFood();
	void keyCheck();

public:
	Game(int width, int height);
	~Game();
	void run();
};