#include "Menu.h"
void initMenuButtons(Rectangle &playButton, Rectangle &exitButton){
	playButton.x = GetScreenWidth()/2-50;
	playButton.y = GetScreenHeight()/2+10;
	playButton.height = 10;
	playButton.width = 100;

	exitButton.x = GetScreenWidth() / 2 - 100;
	exitButton.y = GetScreenHeight() / 2 + 10;
	exitButton.height = 10;
	exitButton.width = 100;
}
void drawBackground() {
	BeginDrawing();
	ClearBackground(BLACK);
	EndDrawing();
}
void drawMenuButton(Rectangle rect){
	BeginDrawing();
	DrawRectangleRec(rect, RED);
	EndDrawing();
}
void drawMenuText(Player player1, Player player2) {
	DrawText("Usa las flechas para cambiar el color de las barras!", 140, 30, 20, RAYWHITE);
	DrawText("Presiona 'Play' cuando estes listo para jugar.", 170, 50, 20, RAYWHITE);
	DrawText(TextFormat("P1: %i", player1.Points), GetScreenWidth() / 20, 10, 20, RAYWHITE);
	DrawText(TextFormat("P2: %i", player2.Points), GetScreenWidth() - GetScreenWidth() / 10, 10, 20, RAYWHITE);
	DrawText("Play", playButton.x + 30, playButton.y + 15, 20, RAYWHITE);
	DrawText("Exit", exitButton.x + 30, exitButton.y + 15, 20, RAYWHITE);
}
void initTriangles(Triangle &prevColor, Triangle &nextColor, Player player) {
	prevColor.TriBase.x=(player.Position.x+(player.Size.x/2))-10;
	prevColor.TriBase.y=(player.Position.y+(player.Size.y/2)-10);
	prevColor.TriCat1.x=(player.Position.x+(player.Size.x/2))-20;
	prevColor.TriCat1.y=(player.Position.y+(player.Size.y/2));
	prevColor.TriCat2.x=(player.Position.x+(player.Size.x/2))-10;
	prevColor.TriCat2.y=(player.Position.y+(player.Size.y/2)+10);

	nextColor.TriBase.x=(player.Position.x+(player.Size.x/2))+10;
	nextColor.TriBase.y=(player.Position.y+(player.Size.y/2)-10);
	nextColor.TriCat1.x=(player.Position.x+(player.Size.x/2))+10;
	nextColor.TriCat1.y=(player.Position.y+(player.Size.y/2)+10);
	nextColor.TriCat2.x=(player.Position.x+(player.Size.x/2)+20);
	nextColor.TriCat2.y=(player.Position.y+(player.Size.y/2));
}
void drawTriangles(Triangle prevColor,Triangle nextColor){
	DrawTriangle(prevColor.TriBase,prevColor.TriCat1,prevColor.TriCat2,VIOLET);
	DrawTriangle(nextColor.TriBase,nextColor.TriCat1,nextColor.TriCat2,VIOLET);
}
bool cursorOnTriangle(Triangle tri,Cursor cursor){
	CheckCollisionPointTriangle(menuCursor.Position, prevColor.TriBase, prevColor.TriCat1, prevColor.TriCat2);
}
void clickTriangle(Player player, Player otherPlayer){
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && cursorOnTriangle(prevColor,menuCursor)) {
		player.ColorCounter--;
		if (player.ColorCounter == otherPlayer.ColorCounter) {player.ColorCounter--;}
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && cursorOnTriangle(nextColor, menuCursor)) {
		player.ColorCounter++;
		if (player.ColorCounter == otherPlayer.ColorCounter) {player.ColorCounter++; }
	}
	if (player.ColorCounter < 0) {
		player.ColorCounter = 8;
	}
	if (player.ColorCounter > 8)
	{
		player.ColorCounter = 0;
	}
}
void changePlayerColor(Player player) {
	switch (player.ColorCounter)
	{
	case 0:
		player.Color = BLUE;
		break;
	case 1:
		player.Color= SKYBLUE;
		break;
	case 2:
		player.Color = DARKBLUE;
		break;
	case 3:
		player.Color = MAROON;
		break;
	case 4:
		player.Color = YELLOW;
		break;
	case 5:
		player.Color = GREEN;
		break;
	case 6:
		player.Color = LIME;
		break;
	case 7:
		player.Color = BROWN;
		break;
	case 8:
		player.Color = DARKBROWN;
		break;
	}
}