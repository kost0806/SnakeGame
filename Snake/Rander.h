#include <ctime>
#include <string>
#include <iostream>
#include <Windows.h>

constexpr int FRAME = 60;
constexpr time_t MS_PER_FRAME = 1000 / FRAME;

class Rander {
private:
	int width, height;
	DWORD last_randered = 0;
	DWORD curr_time;
	int **map;

public:
	Rander(int width, int height);
	void setMap(int **map);
	void randerMapForce(int **map);
	void randerMap(int **map);
	void randerString(std::string msg);

};

