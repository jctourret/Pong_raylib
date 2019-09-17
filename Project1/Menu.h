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

struct MenuButton {
	Vector2 Size;
	Vector2 Position;
};

MenuButton playButton;
MenuButton exitButton;

struct Triangle
{
	Vector2 TriBase;
	Vector2 TriCat1;
	Vector2 TriCat2;
	Vector2 Position;
};

Triangle prevColor;
Triangle nextColor;

void initTriangles(Triangle &prevColor, Triangle &nextColor, Player player);
void drawTriangles(Triangle prevColor, Triangle nextColor);
void buttonPress();