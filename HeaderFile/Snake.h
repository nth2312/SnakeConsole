#pragma once
#include "util.h"
#include "Point.h"
#include "Map.h"
#include <list>
using namespace std;

class Snake{
public:
	list<Point> _body;
	int _status;
	DIR _dir;
	Map *_pmap;
	int _isAlive;

	//method
	Snake(Map *p);

	void Eat();
	void Move();
	void Check();
	void CheckStatus();
	void DisplaySnake();
};
