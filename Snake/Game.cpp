#include "Game.h"
#include <conio.h>
#include <cstdlib>

Game::Game(int width, int height) : rander(width, height) {
	this->width = width;
	this->height = height;
	this->map = new int*[height];
	for (int i = 0; i < height; ++i) {
		this->map[i] = new int[width];
	}
	this->rander.setMap(this->map);
}

Game::~Game() {
	for (int i = 0; i < height; ++i) {
		delete[] map[i];
	}
	delete[] map;
}

void Game::run() {
	setup();
	this->rander.randerMapForce(this->map);
	while (!bGameOver) {
		keyCheck();
		update();
		this->rander.randerMap(this->map);
		Sleep(10);
	}
}

void Game::update() {
	if ((this->curr_time = GetTickCount()) > this->last_update + this->speed) {
		this->last_update = curr_time;
		Point head = this->snake.head();
		int _x = head.x + this->dx[this->direction];
		int _y = head.y + this->dy[this->direction];
		
		// Check bound
		if (_x < 0 || _x >= height || _y < 0 || _y >= width) {
			bGameOver = true;
			return;
		}

		Point tail = this->snake.moveTo(Point(_x, _y), this->map[_x][_y] == 2);
		if (tail.x != -1 && tail.y != -1) {
			this->map[tail.x][tail.y] = 0;
		}
		else {
			if (this->speed > 80) {
				this->speed = (time_t)(this->speed * 0.85);
			}
			nextFood();
		}
		
		// Check crashing
		if (this->snake.isCrash()) {
			bGameOver = true;
			return;
		}


		this->last_direction = this->direction;
		this->map[_x][_y] = 1;
	}
}

void Game::setup() {
	this->snake.moveTo(Point(0, 0), true);

	// init map
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			this->map[i][j] = 0;
		}
	}
	this->map[0][0] = 1;
	nextFood();
	this->rander.setMap(this->map);

	srand(time(NULL));

	this->speed = 150;
}

void Game::nextFood() {
	int x, y;
	do {
		x = rand() % height;
		y = rand() % width;
	} while (this->map[x][y] != 0);
	this->map[x][y] = 2;
}

void Game::keyCheck() {
	if (_kbhit()) {
		int key = _getch();
		if (key == 224) {
			switch (_getch()) {
			case 72:
				if (this->last_direction == 1)
					break;
				this->direction = 0;
				break;
			case 75:
				if (this->last_direction == 3)
					break;
				this->direction = 2;
				break;
			case 77:
				if (this->last_direction == 2)
					break;
				this->direction = 3;
				break;
			case 80:
				if (this->last_direction == 0)
					break;
				this->direction = 1;
				break;
			}
		}
	}
}
