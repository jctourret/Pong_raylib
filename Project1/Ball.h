#pragma once
#include "raylib.h"
#include  "Player.h"
struct Ball {
	Vector2 Position;
	Color Color = WHITE;
	Vector2 Speed = { 7.5f,6.0f };
	int Radius = 10;
};
Ball playBall;

void ballMove(Ball ball);
void ballBouncesWall(Player& player1, Player player2, Ball ball);
void ballBouncesPlayer(Player player, Ball ball);