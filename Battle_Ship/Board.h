#pragma once
#include <iostream>
#include <ctime>


using namespace std;

constexpr int R = 32;

class Board
{
	char plansza[33][33];
	char eplansza[33][33];
	char screen[R][2 * R + 10];   // 32 74
	int x;
	int y;
	int m2;
	int m3;
	int m4;
	int m5;

	
public:
	Board(int wspx, int wspy, int m2s,int m3s,int m4s, int m5s);
	void set_x(int x);
	void set_y(int y);
	void showboard();
	void showscreen();
	void createboard();
	void createenemyboard();
	void createscreen();
	void random_board();
	bool attack(int x , int y);
	void load_ships();
	void nanies(int xc, int yc);
	void naniesB(int xc, int yc);
};

