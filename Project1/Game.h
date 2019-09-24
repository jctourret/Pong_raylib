#pragma once
#include "Player.h"
enum GameState {
	Menu = 0,
	Gameplay = 1,
	Exit = 2
};
void init();
void input();
void update();
void draw();
