#include <Windows.h>
#include <iostream>
using namespace std;

void GoToxy(int x, int y){
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = {x, y};
	SetConsoleCursorPosition(h, c);
}

void Clearxy(int x, int y){
	GoToxy(x, y);
	cout << ' ';
}
