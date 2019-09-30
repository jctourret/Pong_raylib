#include "Game.h"
#include "Menu.h"
#include "Gameplay.h"
#include "Player.h"
#include "raylib.h"

struct Triangle
{
	Vector2 TriBase;
	Vector2 TriCat1;
	Vector2 TriCat2;
	Vector2 Position;
};

Cursor menuCursor;


Rectangle playButton;
Rectangle exitButton;

Triangle prevColorP1;
Triangle nextColorP1;
Triangle prevColorP2;
Triangle nextColorP2;

bool triangleIsClicked(Triangle prevColor, Cursor menuCursor);
void initMenuButtons(Rectangle &playButton, Rectangle &exitButton);
void drawBackground();
void drawMenuText();
void initTriangles(Triangle &prevColor, Triangle &nextColor, Player player);
void drawTriangles(Triangle prevColor, Triangle nextColor, Player player);
void setPrevColor(Player &player, Player otherPlayer, Triangle prevColor, Cursor menuCursor);
void setNextColor(Player &player, Player otherPlayer, Triangle nextColor, Cursor menuCursor);
void changePlayerColor(Player &player);

void initScreen();
void updateMenu();
void drawMenu();

void runMenu() {
	updateMenu();
	drawMenu();
}
void initMenu(){
	initMenuButtons(playButton, exitButton);
	initPlayers(player1, player2);
	initTriangles(prevColorP1, nextColorP1, player1);
	initTriangles(prevColorP2, nextColorP2, player2);
}
void updateMenu(){
	followMenuCursor(menuCursor);
	setPrevColor(player1, player2, prevColorP1, menuCursor);
	setPrevColor(player2, player1, prevColorP2, menuCursor);
	setNextColor(player1, player2, nextColorP1, menuCursor);
	setNextColor(player2, player1, nextColorP2, menuCursor);
	changePlayerColor(player1);
	changePlayerColor(player2);
	exitGame(menuCursor, exitButton);
	startGame(menuCursor, playButton,GameState);
}
void drawMenu() {
	BeginDrawing();
	drawBackground();
	drawMenuButton(playButton);
	drawMenuButton(exitButton);
	drawMenuText();
	DrawCircleV(menuCursor.Position, menuCursor.Radius,YELLOW);
	drawPlayer(player1);
	drawPlayer(player2);
	drawTriangles(prevColorP1, nextColorP1, player1);
	drawTriangles(prevColorP2, nextColorP2, player2);
	EndDrawing();
}
void followMenuCursor(Cursor &cursor) {
	cursor.Position = GetMousePosition();
}
void initMenuButtons(Rectangle &playButton, Rectangle &exitButton) {
	playButton.height = 50;
	playButton.width = 100;
	playButton.x = static_cast<float>(GetScreenWidth()) / 2-(playButton.width/2);
	playButton.y = static_cast<float>(GetScreenHeight()) / 2+(1.5*playButton.height);

	exitButton.height = 50;
	exitButton.width = 100;
	exitButton.x = static_cast<float>(GetScreenWidth()) / 2-(exitButton.width/2);
	exitButton.y = static_cast<float>(GetScreenHeight()) / 2+(3*exitButton.height);
}
void drawBackground() {
	ClearBackground(BLACK);
}
bool buttonIsClicked(Cursor cursor, Rectangle rect) {
	if (CheckCollisionCircleRec(cursor.Position, static_cast<float>(cursor.Radius), rect)
		&& IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		return true;
	}
	else {
		return false;
	}
}
void drawMenuButton(Rectangle rect) {
	DrawRectangleRec(rect, RED);
}
void drawMenuText(){
	DrawText("Usa las flechas para cambiar el color de las barras!", GetScreenWidth()/2-GetScreenWidth()/5, 30, 20, RAYWHITE);
	DrawText("Presiona 'Play' cuando estes listo para jugar.", GetScreenWidth()/2-GetScreenWidth()/6, 50, 20, RAYWHITE);
	DrawText("Play",static_cast<int>(playButton.x)+static_cast<int>(playButton.width)/3, static_cast<int>(playButton.y) + static_cast<int>(exitButton.height)/3, 20, RAYWHITE);
	DrawText("Exit",static_cast<int>(exitButton.x)+static_cast<int>(playButton.width)/3, static_cast<int>(exitButton.y) + static_cast<int>(exitButton.height)/3, 20, RAYWHITE);
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
	DrawTriangle(prevColor.TriBase, prevColor.TriCat1, prevColor.TriCat2, VIOLET);
	DrawTriangle(nextColor.TriBase, nextColor.TriCat1, nextColor.TriCat2, VIOLET);
}
bool triangleIsClicked(Triangle prevColor, Cursor menuCursor) {
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointTriangle(menuCursor.Position, prevColor.TriBase, prevColor.TriCat1, prevColor.TriCat2)) {
		return true;
	}
	else{
		return false;
	}
}
void setPrevColor(Player &player, Player otherPlayer, Triangle prevColor, Cursor menuCursor) {
	if (triangleIsClicked(prevColor, menuCursor)) {
		player.ColorCounter--;
		if (player.ColorCounter == otherPlayer.ColorCounter) { player.ColorCounter--; }
	}
	if (player.ColorCounter < 0) {
		player.ColorCounter = 8;
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
void exitGame(Cursor cursor,Rectangle button) {
	if (buttonIsClicked(cursor,button)) {
		CloseWindow();
	}
}
void startGame(Cursor cursor, Rectangle button, GameStates &gamestate) {
	if (buttonIsClicked(cursor, button)) {
		resetPlayerPoints(player1, player2);
		gamestate = Gameplay;
	}
}