#pragma once
#include "raylib.h"

using namespace std;
struct Player {
	Vector2 Size;
	Vector2 Position;
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
