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

extern Player player1;
extern Player player2;

void drawPlayer(Player player);
void player1Move(Player &player1);
void player2Move(Player &player2);
#endif BALL_H