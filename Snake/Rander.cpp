#include "Rander.h"
#include <cstdlib>
#include <cstdio>

Rander::Rander(int width, int height) {
	this->width = width;
	this->height = height;
}

void Rander::setMap(int ** map) {
	this->map = new int*[this->height];
	for (int i = 0; i < this->height; ++i) {
		this->map[i] = new int[width];
		for (int j = 0; j < this->width; ++j) {
			this->map[i][j] = map[i][j];
		}
	}
}

void Rander::randerMapForce(int ** map) {
	for (short i = 0; i < this->height; ++i) {
		for (short j = 0; j < this->width; ++j) {
			switch (map[i][j]) {
			case 0: // blank
				printf("бр");
				break;
			case 1: // body
				printf("бс");
				break;
			case 2: // food
				printf("б▄");
				break;
			}
		}
		printf("\n");
	}
}



void Rander::randerMap(int ** map) {
	if ((curr_time = GetTickCount()) > last_randered + MS_PER_FRAME) {
		this->last_randered = curr_time;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)this->height, (short)this->width});
		//std::system("cls");
		for (short i = 0; i < this->height; ++i) {
			for (short j = 0; j < this->width; ++j) {
				if (this->map[i][j] != map[i][j]) {
					this->map[i][j] = map[i][j];
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { j * 2, i });
					switch (map[i][j]) {
					case 0: // blank
						printf("бр");
						break;
					case 1: // body
						printf("бс");
						break;
					case 2: // food
						printf("б▄");
						break;
					}
				}
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)this->height, (short)this->width });
			}
		}
	}
}

void Rander::randerString(std::string msg) {
	std::cout << msg << "\n";
}
