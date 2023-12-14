#include "Snake.h"
#include "Point.h"
#include "Map.h"

Snake::Snake(Map* p){
	_dir = RIGHT;
	_isAlive = 1;
	_body.push_back(Point(4, 1, '@'));
	_body.push_back(Point(3, 1, 'O'));
	_body.push_back(Point(2, 1, 'O'));
	_body.push_back(Point(1, 1, 'O'));
	_pmap = p;
	_status = 0;
}

void Snake::DisplaySnake(){
	for (auto i = _body.begin(); i != _body.end(); i ++){
		(*i).DrawPoint();
		_pmap->_map[(*i)._y][(*i)._x] = (*i)._c;
	}
}

void Snake::Move(){
	int nx, ny;
	if (_dir == UP){
		nx = _body.front()._x;
		ny = _body.front()._y - 1;
	}
	else if (_dir == RIGHT){
		nx = _body.front()._x + 1;
		ny = _body.front()._y;
	}
	else if (_dir == DOWN){
		nx = _body.front()._x;
		ny = _body.front()._y + 1;
	}
	else{
		nx = _body.front()._x - 1;
		ny = _body.front()._y;
	}
	Point newHead = Point(nx, ny, '@');
	if (_pmap->_map[ny][nx] == '#' || _pmap->_map[ny][nx] == 'O'){
		_status = -1;
		return;
	}
	_body.front()._c = 'O';
	_body.push_front(newHead);

	if (_status == 0){
		Clearxy(_body.back()._x, _body.back()._y);
		_pmap->_map[_body.back()._y][_body.back()._x] = ' ';
		_body.pop_back();
	}
}
