#include "Map.h"
#include <iostream>
using namespace std;

Map::Map(){
	_w = 50;
	_h = 25;
	char **p = new char*[_h];
	for (int row = 0; row < _h; row ++){
		p[row] = new char[_w];
		for (int col = 0; col < _w; col ++){
			if (row == 0 || row == _h - 1 || col == 0 || col == _w - 1)
				p[row][col] = '#';
			else
				p[row][col] = ' ';
		}
	}
	_map = p;
}

void Map::DisplayMap(){
	for (int row = 0; row < _h; row ++){
		for (int col = 0; col < _w; col ++){
			cout << _map[row][col];
		}
		cout << endl;
	}
}

Map::~Map(){
	for (int row = 0; row < _h; row ++){
		delete[] _map[row];
	}
	delete _map;
	_map = 0;
	_w = 0; _h = 0;
}
