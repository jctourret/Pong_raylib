#pragma once
#include "raylib.h"
#include "Player.h"
using namespace std;

struct Cursor {
	Vector2 Position;
	Color Color = WHITE;
	Vector2 Speed = { 7.5f,6.0f };
	int Radius = 10;
};
Cursor menuCursor;

Rectangle playButton;
Rectangle exitButton;

struct Triangle
{
	Vector2 TriBase;
	Vector2 TriCat1;
	Vector2 TriCat2;
	Vector2 Position;
};

Triangle prevColor;
Triangle nextColor;

void drawBackground();
void initMenuButtons(Rectangle &playButton, Rectangle &exitButton);
void drawMenuButton(Rectangle rect);
void drawMenuText(Player player1, Player player2);
void initTriangles(Triangle &prevColor, Triangle &nextColor, Player player);
void drawTriangles(Triangle prevColor, Triangle nextColor);
bool cursorOnTriangle(Triangle tri, Cursor cursor);
void clickTriangle(Player player, Player otherPlayer);
void changePlayerColor(Player &player);