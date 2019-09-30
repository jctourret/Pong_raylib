#include "Game.h"
#include "raylib.h"
#include "Menu.h"
#include "Gameplay.h"
#include "Exit.h"

GameStates GameState;
void initScreen();

void runGame() {
	initScreen();
	initMenu();
	initGameplay();
	while (!WindowShouldClose()) {
		switch (GameState) {
		case Menu:
			runMenu();
			break;
		case Gameplay:
			runGameplay();
			break;
		case Exit:
			runExit();
			break;
		}
	}
}
void initScreen() {
	const int screenWidth = 800;
	const int screenHeight = 400;
	InitWindow(screenWidth, screenHeight, "Pong");
	SetTargetFPS(60);
}

