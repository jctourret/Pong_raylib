#include "Player.h"
void drawPlayer(Player player){
	BeginDrawing();
	DrawRectangleRec(player.Body, player.Color);
	EndDrawing();
}
void player1Move(Player &player1) {
	if (IsKeyDown(KEY_W))player1.Body.y -= player1.Speed;
	if (IsKeyDown(KEY_S))player1.Body.y += player1.Speed;
}
void player2Move(Player &player2) {
	if (IsKeyDown(KEY_UP))player2.Body.y -= player2.Speed;
	if (IsKeyDown(KEY_DOWN))player2.Body.y += player2.Speed;
}