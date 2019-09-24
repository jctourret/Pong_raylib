#pragma once
#include "Player.h"
#include "Ball.h"
bool checkGameState(Player player);
void drawGameplay();
void ballBouncesWall(Player &player1, Player &player2, Ball ball);
void ballBouncesPlayer(Player player, Ball &ball);
void playerCollidesW(Player player);