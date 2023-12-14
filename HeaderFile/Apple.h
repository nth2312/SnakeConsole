#pragma once
#include "Point.h"
#include "Map.h"


class Apple{
public:
	Point _pos;
	int _status;
	Map* _pmap;

	//method
	Apple();

	Apple(Map* p);

	void GeneratePosition();
	//void CheckStatus();
	void ClearApple();
	void DisplayApple();
};
