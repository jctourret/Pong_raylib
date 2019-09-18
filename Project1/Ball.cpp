#include "Ball.h"

void ballMove(Ball ball) {
	ball.Position.x += ball.Speed.x;
	ball.Position.y += ball.Speed.y;
}
void ballBouncesWall(Player player1, Player player2,Ball ball) {
	if ((ball.Position.x >= (GetScreenWidth() - ball.Radius))) {
		ball.Position.x = GetScreenWidth() / 2;
		ball.Position.y = GetScreenHeight() / 2;
		player1.Points++;
		ball.Speed.x = 7.5f;
		ball.Speed.y = 6.0f;
	}
	if (ball.Position.x <= ball.Radius) {
		ball.Position.x = GetScreenWidth() / 2;
		ball.Position.y = GetScreenHeight() / 2;
		player2.Points++;
		ball.Speed.x = -7.5f;
		ball.Speed.y = -6.0f;
	}
	if ((ball.Position.y >= (GetScreenHeight() - ball.Radius)) || (ball.Position.y <= ball.Radius))ball.Speed.y *= -1.0f;
}
bool ballHittingPlayer(Ball ball, Player player) {
	CheckCollisionCircleRec(ball.Position, ball.Radius, player.Body);
}
void ballBouncesPlayer(Player player, Ball ball) {
	ballHittingPlayer(ball, player);
	bool hasCollided=false;
	if(hasCollided==false&&ballHittingPlayer(ball, player)){
		if(player.Body.y+player2.Body.height/4>=ball.Position.y){
			if(ball.Speed.y>0){ball.Speed.y=-ball.Speed.y-4;}// si esta bajando que la invierta y acelere
			if(ball.Speed.y<0){ball.Speed.y-4;} //si esta subiendo que acelere
		}
		if (player.Body.y+player.Body.height/2>=ball.Position.y&&player.Body.y+player.Body.height/4<ball.Position.y){
			if(ball.Speed.y>0){ball.Speed.y=-ball.Speed.y-2;} // si esta bajando que la invierta y acelere
			if(ball.Speed.y<0){ball.Speed.y-2;} // si esta subiendo que acelere
		}
		if (player.Body.y+player.Body.height/2<ball.Position.y&&player2.Body.y+player2.Body.height/2+player2.Body.height/4>ball.Position.y){
			if(ball.Speed.y<0){ball.Speed.y=-ball.Speed.y+2;} // si esta subiendo que se invierta  y acelere
			if(ball.Speed.y>0){ball.Speed.y+2;} // si esta bajando acelera
		}
		if (player.Body.y+player.Body.height/2+player.Body.height/4<=ball.Position.y){
			if(ball.Speed.y<0){ball.Speed.y=-ball.Speed.y+4;}
			if(ball.Speed.y>0){ball.Speed.y+4;}
		}
		ball.Speed.x=-ball.Speed.x;
		hasCollided=true;
		ball.Color=player.Color;
	}
	if (!(ballHittingPlayer(ball, playe))) {
		hasCollided = false;
	}
}