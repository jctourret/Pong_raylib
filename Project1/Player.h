#pragma once
#include "raylib.h"

using namespace std;
struct Player {
	Rectangle Body;
	int Speed = 8;
	bool Win;
	Color Color;
	int Points;
	int ColorCounter;
};

Player player1;
Player player2;

void drawPlayer(Player player);
void playerCollidesW(Player player);
void player1Move(Player &player1);
void player2Move(Player &player2);