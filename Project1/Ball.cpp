#include "Ball.h"
void initBall(Ball &ball) {
	ball.Position.x = GetScreenWidth() / 2;
	ball.Position.y = GetScreenHeight() / 2;
	ball.Speed.x = GetScreenWidth() / 100;
	ball.Speed.y = GetScreenHeight() / 100;
	ball.Radius = 10;
	ball.Color = YELLOW;
}
void moveBall(Ball &ball) {
	ball.Position.x += ball.Speed.x;
	ball.Position.y += ball.Speed.y;
}
void drawBall(Ball ball) {
	DrawCircleV(ball.Position, ball.Radius, ball.Color);
}