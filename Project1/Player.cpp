#include "Player.h"
Player player1;
Player player2;
void initPlayers(Player &player,Player &otherPlayer) {
	player.Body.x = GetScreenWidth() / 20;
	player.Body.y = GetScreenHeight() / 2;
	player.Body.height = 100;
	player.Body.width = 6;
	player.ColorCounter = 0;
	otherPlayer.Body.x = GetScreenWidth() - GetScreenWidth() / 20;
	otherPlayer.Body.y = GetScreenHeight() / 2;
	otherPlayer.Body.height = 100;
	otherPlayer.Body.width = 6;
	otherPlayer.ColorCounter = 3;
}
void drawPlayer(Player player){
	DrawRectangleRec(player.Body, player.Color);
}
void movePlayer1(Player &player1) {
	if (IsKeyDown(KEY_W))player1.Body.y -= player1.Speed;
	if (IsKeyDown(KEY_S))player1.Body.y += player1.Speed;
}
void movePlayer2(Player &player2) {
	if (IsKeyDown(KEY_UP))player2.Body.y -= player2.Speed;
	if (IsKeyDown(KEY_DOWN))player2.Body.y += player2.Speed;
}
void resetPlayerPoints(Player &player,Player &otherPlayer) {
	player.Points = 0;
	otherPlayer.Points = 0;
}