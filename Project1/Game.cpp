#include "Juego.h"

void init() {
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
	int colorCounterP1 = 0;
	int colorCounterP2 = 4;
	bool rect1Collision = false;
	bool rect2Collision = false;
	bool rect1PrevColor = false;
	bool rect1NextColor = false;
	bool rect2PrevColor = false;
	bool rect2NextColor = false;
	bool gameMenuOn;
	SetTargetFPS(60);
}

void update() {
	
}