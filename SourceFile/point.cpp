#include "Point.h"
#include "util.h"
#include <iostream>
using namespace std;

Point::Point(int x, int y, char c){
	_x = x;
	_y = y;
	_c = c;
}

void Point::DrawPoint(){
	GoToxy(_x, _y);
	cout << _c;
}
