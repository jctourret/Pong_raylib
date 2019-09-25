#ifndef BALL_H
#define BALL_H

#include  "Player.h"
#include "raylib.h"
struct Ball {
	Vector2 Position;
	Color Color = WHITE;
	Vector2 Speed = { 7.5f,6.0f };
	float Radius = 10;
};
extern Ball playBall;

void moveBall(Ball &ball);
void drawBall(Ball ball);
#endif BALL_H