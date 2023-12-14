#pragma once
#include "Apple.h"
#include "Snake.h"
#include "Map.h"


class Game{
public:
	int _score;
	Map *_mapGame;
	Apple *_apple;
	Snake *_snake;

	//method
	Game();

	void KeyboardHandle();
	void Loop();
	void CheckEat();
	void DisplayScore();
};
