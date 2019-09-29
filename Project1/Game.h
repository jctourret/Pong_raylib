#ifndef GAME_H
#define GAME_H
enum GameStates {
	Menu,
	Gameplay,
	Exit
};
extern GameStates GameState;
void runGame();
#endif GAME_H