#include "Game.h"
#include "raylib.h"
#include "Menu.h"
#include "Gameplay.h"

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
void input() {

}
void update() {
	
}
void draw() {
	BeginDrawing();
	drawBackground();
	drawMenuButton(playButton);
	drawMenuButton(exitButton);
	drawMenuText(player1,player2);
	drawTriangles(prevColor,nextColor);
	EndDrawing();
}