#include "Exit.h"
#include "Game.h"
#include "Menu.h"
#include "Player.h"
#include "raylib.h"

void updateExit();
void drawExit();
void drawWhoWins(Player player);
void drawMenuText();
void drawMenuButton(Rectangle rect);
void drawExitText();


void runExit(){
	updateExit();
	drawExit();
}
void updateExit() {
	followMenuCursor(menuCursor);
	startGame(menuCursor, playButton, GameState);
	exitGame(menuCursor, exitButton);
}
void drawExit() {
	BeginDrawing();
	ClearBackground(BLACK);
	drawWhoWins(player1);
	drawMenuButton(playButton);
	drawMenuButton(exitButton);
	drawExitText();
	DrawCircleV(menuCursor.Position, menuCursor.Radius, YELLOW);
	EndDrawing();
}
void drawWhoWins(Player player) {
	if (player.Win == true) {
		DrawText("Player 1 Wins!", GetScreenWidth()/2-GetScreenWidth()/5, GetScreenHeight()/2, 50, RAYWHITE);
	}
	else{
		DrawText("Player 2 Wins!", GetScreenWidth() / 2 - GetScreenWidth() / 5, GetScreenHeight() / 2, 50, RAYWHITE);
	}
}
void drawExitText() {
	DrawText("Play", static_cast<int>(playButton.x) + static_cast<int>(playButton.width) / 3, static_cast<int>(playButton.y) + static_cast<int>(exitButton.height) / 3, 20, RAYWHITE);
	DrawText("Exit", static_cast<int>(exitButton.x) + static_cast<int>(playButton.width) / 3, static_cast<int>(exitButton.y) + static_cast<int>(exitButton.height) / 3, 20, RAYWHITE);
}