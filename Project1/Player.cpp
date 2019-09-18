#include "Player.h"

void drawPlayer(Player player){
	BeginDrawing();
	DrawRectangleRec(player.Body, player.Color);
	EndDrawing();
}
void playerCollidesW(Player player) {
	if ((player.Body.y + player.Body.height) >= GetScreenHeight()) player.Body.y = GetScreenHeight() - player.Body.height;
	else if (player.Body.y <= 0) player.Body.y = 0;
}
void player1Move(Player &player1) {
	if (IsKeyDown(KEY_W))player1.Body.y -= player1.Speed;
	if (IsKeyDown(KEY_S))player1.Body.y += player1.Speed;
}
void player2Move(Player &player2) {
	if (IsKeyDown(KEY_UP))player2.Body.y -= player2.Speed;
	if (IsKeyDown(KEY_DOWN))player2.Body.y += player2.Speed;
}