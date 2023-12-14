#include "Apple.h"
#include "Map.h"
#include <time.h>
#include <stdlib.h>
#include "util.h"

Apple::Apple(){
	_pmap = 0;
}

Apple::Apple(Map* p){
	_pmap = p;
}

void Apple::DisplayApple() {
	_pos.DrawPoint();
}

void Apple::ClearApple() {
	Clearxy(_pos._x, _pos._y);
	_pmap -> _map[_pos._y][_pos._x] = ' ';
}

void Apple::GeneratePosition() {
	//ClearApple();
	srand(time(NULL));
	while (1){
		int x = (rand() % (_pmap->_w - 2)) + 1;
		int y = (rand() % (_pmap->_h - 2)) + 1;

		//check
		if (_pmap -> _map[y][x] == ' '){
			_pos = Point(x, y, '@');
			break;
		}
	}

	DisplayApple();
}
