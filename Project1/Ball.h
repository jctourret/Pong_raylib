#pragma once
#include  "Player.h"
#include "raylib.h"
struct Ball {
	Vector2 Position;
	Color Color = WHITE;
	Vector2 Speed = { 7.5f,6.0f };
	int Radius = 10;
};
Ball playBall;

void moveBall(Ball &ball);
void drawBall(Ball ball);