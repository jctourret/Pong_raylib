#include "Menu.h"
#include "Player.h"
#include "raylib.h"

struct Cursor {
	Vector2 Position;
	Color Color = WHITE;
	Vector2 Speed = { 7.5f,6.0f };
	int Radius = 10;
};

extern Cursor menuCursor;

Rectangle playButton;
Rectangle exitButton;

struct Triangle
{
	Vector2 TriBase;
	Vector2 TriCat1;
	Vector2 TriCat2;
	Vector2 Position;
};

Triangle prevColorP1;
Triangle nextColorP1;
Triangle prevColorP2;
Triangle nextColorP2;

void initMenuButtons(Rectangle &playButton, Rectangle &exitButton);
void drawBackground();
bool buttonIsClicked(Cursor cursor, Rectangle rect);
void drawMenuButton(Rectangle rect);
void drawMenuText();
void initTriangles(Triangle &prevColor, Triangle &nextColor, Player player);
void drawTriangles(Triangle prevColor, Triangle nextColor, Player player);
bool triangleIsClicked(Triangle prevColor, Cursor menuCursor);
void setPrevColor(Player &player, Player otherPlayer, Triangle prevColor, Cursor menuCursor);
void setNextColor(Player &player, Player otherPlayer, Triangle nextColor, Cursor menuCursor);

void runMenu() {
	initMenuButtons(playButton, exitButton);
	BeginDrawing();
	drawBackground();
	drawMenuButton(playButton);
	drawMenuButton(exitButton);
	drawMenuText();
	drawTriangles(prevColorP1, nextColorP1, player1);
	drawTriangles(prevColorP2, nextColorP2, player2);

}
void initMenuButtons(Rectangle &playButton, Rectangle &exitButton) {
	playButton.x = GetScreenWidth() / 2 - 50;
	playButton.y = GetScreenHeight() / 2 + 10;
	playButton.height = 10;
	playButton.width = 100;

	exitButton.x = GetScreenWidth() / 2 - 100;
	exitButton.y = GetScreenHeight() / 2 + 10;
	exitButton.height = 10;
	exitButton.width = 100;
}
void drawBackground() {
	ClearBackground(BLACK);
}
bool buttonIsClicked(Cursor cursor, Rectangle rect) {
	if (CheckCollisionCircleRec(cursor.Position, cursor.Radius, rect)
		&& IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		return true;
	}
}
void drawMenuButton(Rectangle rect) {
	DrawRectangleRec(rect, RED);
}
void drawMenuText() {
	DrawText("Usa las flechas para cambiar el color de las barras!", 140, 30, 20, RAYWHITE);
	DrawText("Presiona 'Play' cuando estes listo para jugar.", 170, 50, 20, RAYWHITE);
	DrawText("Play", playButton.x + 30, playButton.y + 15, 20, RAYWHITE);
	DrawText("Exit", exitButton.x + 30, exitButton.y + 15, 20, RAYWHITE);
}
void initTriangles(Triangle &prevColor, Triangle &nextColor, Player player) {
	prevColor.TriBase.x = (player.Body.x + (player.Body.width / 2)) - 10;
	prevColor.TriBase.y = (player.Body.y + (player.Body.height / 2) - 10);
	prevColor.TriCat1.x = (player.Body.x + (player.Body.width / 2)) - 20;
	prevColor.TriCat1.y = (player.Body.y + (player.Body.height / 2));
	prevColor.TriCat2.x = (player.Body.x + (player.Body.width / 2)) - 10;
	prevColor.TriCat2.y = (player.Body.y + (player.Body.height / 2) + 10);

	nextColor.TriBase.x = (player.Body.x + (player.Body.width / 2)) + 10;
	nextColor.TriBase.y = (player.Body.y + (player.Body.height / 2) - 10);
	nextColor.TriCat1.x = (player.Body.x + (player.Body.width / 2)) + 10;
	nextColor.TriCat1.y = (player.Body.y + (player.Body.height / 2) + 10);
	nextColor.TriCat2.x = (player.Body.x + (player.Body.width / 2) + 20);
	nextColor.TriCat2.y = (player.Body.y + (player.Body.height / 2));
}
void drawTriangles(Triangle prevColor, Triangle nextColor, Player player) {
	initTriangles(prevColor, nextColor, player);
	DrawTriangle(prevColor.TriBase, prevColor.TriCat1, prevColor.TriCat2, VIOLET);
	DrawTriangle(nextColor.TriBase, nextColor.TriCat1, nextColor.TriCat2, VIOLET);
}
bool triangleIsClicked(Triangle prevColor, Cursor menuCursor) {
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointTriangle(menuCursor.Position, prevColor.TriBase, prevColor.TriCat1, prevColor.TriCat2)) {
		return true;
	}
}
void setPrevColor(Player &player, Player otherPlayer, Triangle prevColor, Cursor menuCursor) {
	if (triangleIsClicked(prevColor, menuCursor)) {
		player.ColorCounter--;
		if (player.ColorCounter == otherPlayer.ColorCounter) { player.ColorCounter--; }
	}
	if (player.ColorCounter > 8) {
		player.ColorCounter = 0;
	}
}
void setNextColor(Player &player, Player otherPlayer, Triangle nextColor, Cursor menuCursor) {
	if (triangleIsClicked(nextColor, menuCursor)) {
		player.ColorCounter++;
		if (player.ColorCounter == otherPlayer.ColorCounter) { player.ColorCounter++; }
	}
	if (player.ColorCounter > 8) {
		player.ColorCounter = 0;
	}
}
void changePlayerColor(Player &player) {
	switch (player.ColorCounter) {
	case 0:
		player.Color = BLUE;
		break;
	case 1:
		player.Color = SKYBLUE;
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