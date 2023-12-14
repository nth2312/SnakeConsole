#include "Game.h"
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

Game::Game(){
	_mapGame =new Map();
	_apple = new Apple(_mapGame);
	_snake = new Snake(_mapGame);
	_score = 0;
}

void Game::Loop(){
	_snake->_status = 0;
	_mapGame->DisplayMap();
	_apple->GeneratePosition();
	DisplayScore();
	while(1){
		KeyboardHandle();
		_snake->Move();
		if (_snake->_status == -1){
			break;
		}
		CheckEat();
		_snake->DisplaySnake();
		Sleep(50);
	}
	if (system("CLS")) system("clear");
	cout << "Game Over" << endl;
	system("pause");
}

void Game::KeyboardHandle(){
	if (_kbhit()){
		int kb = _getch();
		if (kb == 75 && _snake->_dir != RIGHT){
			_snake->_dir = LEFT;
		}
		else if (kb == 72 && _snake->_dir != DOWN){
			_snake->_dir = UP;
		}
		else if (kb == 77 && _snake->_dir != LEFT){
			_snake->_dir = RIGHT;
		}
		else if (kb == 80 && _snake->_dir != UP){
			_snake->_dir = DOWN;
		}
	}
}

void Game::CheckEat(){
	Point head = _snake->_body.front();
	if (head._x == _apple->_pos._x && head._y == _apple->_pos._y){
		_score ++;
		_snake->_status = 1;
		_apple->ClearApple();
		_apple->GeneratePosition();
		DisplayScore();
	}
	else
		_snake->_status = 0;
}

void Game::DisplayScore(){
	GoToxy(0, _mapGame->_h + 2);
	cout << "Your score: " << _score;
}
