#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
using namespace std;
struct Player {
	Rectangle Body;
	int Speed = 8;
	bool Win;
	Color Color;
	int Points;
	int ColorCounter;
};

static Player player1;
static Player player2;

void initPlayers(Player &player, Player &otherPlayer);
void drawPlayer(Player player);
void movePlayer1(Player &player1);
void movePlayer2(Player &player2);
#endif BALL_H