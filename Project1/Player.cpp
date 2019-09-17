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