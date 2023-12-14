#pragma once
#include "Point.h"

class Map{
public:
	int _w, _h;
	char **_map;

	//method
	void DisplayMap();
	Map();
	Map(int w, int h);
	Map(int w, int h, char **map);
	~Map();
};
