#include "Player.h"

void drawPlayer(Player player){
	BeginDrawing();
	DrawRectangleV(player.Position, player.Size, player.Color);
	EndDrawing();
}
void playerCollidesW(Player player) {
	if ((player.Position.y + player.Size.y) >= GetScreenHeight()) player.Position.y = GetScreenHeight() - player.Size.y;
	else if (player.Position.y <= 0) player.Position.y = 0;
}
void player1Move(Player &player1) {
	if (IsKeyDown(KEY_W))player1.Position.y -= player1.Speed;
	if (IsKeyDown(KEY_S))player1.Position.y += player1.Speed;
}
void player2Move(Player &player2) {
	if (IsKeyDown(KEY_UP))player2.Position.y -= player2.Speed;
	if (IsKeyDown(KEY_DOWN))player2.Position.y += player2.Speed;
}