#ifndef MENU_H
#define MENU_H
#include "raylib.h"
struct Cursor {
	Vector2 Position;
	Color Color = WHITE;
	Vector2 Speed = { 7.5f,6.0f };
	int Radius = 10;
};
extern Cursor menuCursor;
void runMenu();
void initMenu();
void drawMenuButton(Rectangle rect);
void startGame(Cursor cursor, Rectangle button, GameStates &gamestate);
bool buttonIsClicked(Cursor cursor, Rectangle rect);
void exitGame(Cursor cursor, Rectangle button);
void followMenuCursor(Cursor &cursor);
extern Rectangle playButton;
extern Rectangle exitButton;
#endif MENU_H