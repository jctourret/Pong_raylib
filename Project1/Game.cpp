#include "Game.h"
#include "raylib.h"
#include "Menu.h"
#include "Gameplay.h"
#include "Exit.h"

enum GameStates {
	Menu,
	Gameplay,
	Exit
};
GameStates GameState;
void runGame() {
	switch (GameState) {
	case Menu:
		break;
	case Gameplay:
		break;
	case Exit:
		break;
	}
}
void init() {
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
	SetTargetFPS(60);
}
void input() {

}
void update() {
	
}
void draw() {
	BeginDrawing();
	EndDrawing();
}
