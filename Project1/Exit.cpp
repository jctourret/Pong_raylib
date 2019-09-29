#include "Exit.h"
#include "raylib.h"
struct Cursor {
	Vector2 Position;
	Color Color = WHITE;
	Vector2 Speed = { 7.5f,6.0f };
	int Radius = 10;
};

Cursor menuCursor;
void drawExit();

void runExit(){
	drawExit();
}

void drawExit() {

}
void drawWhoWins() {
	DrawText("Player %i Wins!", (GetScreenWidth() / 2 - GetScreenWidth() / 15), GetScreenHeight() / 10, 10, RAYWHITE);
}