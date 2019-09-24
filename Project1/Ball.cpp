#include "Ball.h"
void moveBall(Ball &ball) {
	ball.Position.x += ball.Speed.x;
	ball.Position.y += ball.Speed.y;
}
void drawBall(Ball ball) {
	DrawCircleV(ball.Position, ball.Radius, ball.Color);
}