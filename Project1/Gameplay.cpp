#include "Game.h"
#include "Gameplay.h"
#include <ctime> 
#include <cstdlib> 

void inputGameplay();
void updateGameplay();
void drawGameplay();
void checkGameState(Player &player);
void ballBouncesWall(Player &player1, Player &player2, Ball &ball);
void ballBouncesPlayer(Player player, Ball &ball);
void playerCollidesW(Player &player);
void exitGame(Player player, GameStates &gamestate);

void runGameplay() {
	inputGameplay();
	updateGameplay();
	drawGameplay();
}
void initGameplay() {
	initBall(playBall);
}
void inputGameplay() {
	movePlayer1(player1);
	movePlayer2(player2);
}
void updateGameplay() {
	checkGameState(player1);
	checkGameState(player2);
	ballBouncesWall(player1, player2, playBall);
	ballBouncesPlayer(player1, playBall);
	ballBouncesPlayer(player2, playBall);
	playerCollidesW(player1);
	playerCollidesW(player2);
	moveBall(playBall);
	exitGame(player1, GameState);
	exitGame(player2, GameState);
}
void drawGameplay() {
	BeginDrawing();
	ClearBackground(BLACK);
	drawBall(playBall);
	drawPlayer(player1);
	drawPlayer(player2);
	drawGameData(player1, player2);
	EndDrawing();
}
void checkGameState(Player &player) {
	if (player.Points >= 10)
	{
		player.Win = true;
	}
	else {
		player.Win = false;
	}
}

void ballBouncesWall(Player &player1, Player &player2, Ball &ball) {
	if ((ball.Position.x >= (GetScreenWidth() - ball.Radius))) {
		ball.Position.x = static_cast<float>(GetScreenWidth()) / 2;
		ball.Position.y = static_cast<float>(GetScreenHeight()) / 2;
		player1.Points++;
		ball.Speed.x = static_cast<float>(GetScreenWidth()) / 100;
		ball.Speed.y = static_cast<float>(GetScreenHeight()) / 100;
	}
	if (ball.Position.x <= ball.Radius) {
		ball.Position.x = static_cast<float>(GetScreenWidth()) / 2;
		ball.Position.y = static_cast<float>(GetScreenHeight()) / 2;
		player2.Points++;
		ball.Speed.x = static_cast<float>(-GetScreenWidth()) / 100;
		ball.Speed.y = static_cast<float>(-GetScreenHeight()) / 100;
	}
	if ((ball.Position.y >= (GetScreenHeight() - ball.Radius)) || (ball.Position.y <= ball.Radius)) {ball.Speed.y *= -1.0f;}
}
void ballBouncesPlayer(Player player, Ball &ball) {
	ballHittingPlayer(ball, player);
	bool hasCollided = false;
	if (hasCollided == false && ballHittingPlayer(ball, player)) {
		if (player.Body.y + player2.Body.height / 4 >= ball.Position.y) {
			if (ball.Speed.y > 0) { ball.Speed.y = -ball.Speed.y - 2; }// si esta bajando que la invierta y acelere
			if (ball.Speed.y < 0) { ball.Speed.y -= 4; } //si esta subiendo que acelere
		}
		if (player.Body.y + player.Body.height / 2 >= ball.Position.y&&player.Body.y + player.Body.height / 4 < ball.Position.y) {
			if (ball.Speed.y > 0) { ball.Speed.y = -ball.Speed.y - 1; } // si esta bajando que la invierta y acelere
			if (ball.Speed.y < 0) { ball.Speed.y -= 1; } // si esta subiendo que acelere
		}
		if (player.Body.y + player.Body.height / 2 < ball.Position.y&&player2.Body.y + player2.Body.height / 2 + player2.Body.height / 4 > ball.Position.y) {
			if (ball.Speed.y < 0) { ball.Speed.y = -ball.Speed.y + 1; } // si esta subiendo que se invierta  y acelere
			if (ball.Speed.y > 0) { ball.Speed.y += 1; } // si esta bajando acelera
		}
		if (player.Body.y + player.Body.height / 2 + player.Body.height / 4 <= ball.Position.y) {
			if (ball.Speed.y < 0) { ball.Speed.y = -ball.Speed.y + 2; }
			if (ball.Speed.y > 0) { ball.Speed.y += 2; }
		}
		if (ball.Speed.x>0)
		{
			ball.Speed.x++;
		}
		if (ball.Speed.x<0)
		{
			ball.Speed.x--;
		}
		ball.Speed.x = -ball.Speed.x;
		hasCollided = true;
		ball.Color = player.Color;
	}
	if (!(ballHittingPlayer(ball, player))) {
		hasCollided = false;
	}
}
void playerCollidesW(Player &player) {
	if ((player.Body.y + player.Body.height) >= GetScreenHeight()) player.Body.y = GetScreenHeight() - player.Body.height;
	else if (player.Body.y <= 0) player.Body.y = 0;
}
void exitGame(Player player, GameStates &gamestate) {
	if (player.Win == true) {
		gamestate = Exit;
	}
}
void drawGameData(Player player1, Player player2) {
	DrawText(TextFormat("P1: %i", player1.Points), GetScreenWidth() / 20, 10, 20, RAYWHITE);
	DrawText(TextFormat("P2: %i", player2.Points), GetScreenWidth() - GetScreenWidth() / 10, 10, 20, RAYWHITE);
}
bool ballHittingPlayer(Ball ball, Player player) {
	if (CheckCollisionCircleRec(ball.Position, ball.Radius, player.Body)) {
		return true;
	}
	else {
		return false;
	}
}