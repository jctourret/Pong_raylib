#ifndef BALL_H
#define BALL_H

#include  "Player.h"
#include "raylib.h"
struct Ball {
	Vector2 Position;
	Color Color = WHITE;
	Vector2 Speed;
	float Radius;
};
static Ball playBall;

void initBall(Ball &ball);
void moveBall(Ball &ball);
void drawBall(Ball ball);
#endif BALL_H