#include "raylib.h"

struct Ball{
	Vector2 Position;
	Color Color = WHITE;
	Vector2 Speed = { 7.5f,6.0f };
	int Radius=10;
};
Ball playBall;
Ball menuBall;



int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	// Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------
	do {
		while (gameMenuOn&&!WindowShouldClose())
		{
			//Menu Buttons
			menuBall.Position=GetMousePosition();
			Rectangle playbutton;
			bool menuCollision = CheckCollisionCircleRec(menuBall.Position, menuBall.Radius, playbutton);
			bool menuCollision2=CheckCollisionCircleRec(menuBall.Position, menuBall.Radius, exitButton);
			if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && menuCollision) {
				gameMenuOn = false;
			}
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && menuCollision2) {
				return 0;
			}
			//Changing bar colors
			
			
			if (colorCounterP2 < 0) {
				colorCounterP2 = 8;
			}
			if (colorCounterP2 > 8)
			{
				colorCounterP2 = 0;
			}
			switch (colorCounterP2)
			{
			case 0:
				rectP2Color = BLUE;
				break;
			case 1:
				rectP2Color = SKYBLUE;
				break;
			case 2:
				rectP2Color = DARKBLUE;
				break;
			case 3:
				rectP2Color = MAROON;
				break;
			case 4:
				rectP2Color = YELLOW;
				break;
			case 5:
				rectP2Color = GREEN;
				break;
			case 6:
				rectP2Color = LIME;
				break;
			case 7:
				rectP2Color = BROWN;
				break;
			case 8:
				rectP2Color = DARKBROWN;
				break;
			}
			//Draw Menu
			BeginDrawing();
			ClearBackground(BLACK);
			DrawRectangleRec(rectMenu,RED);
			DrawRectangleRec(rectMenu4, RED);
			DrawTriangle((Vector2){(rectP2.x+(rectP2.width/2))-10,(rectP2.y+(rectP2.height/2)-10)},
						(Vector2){(rectP2.x+(rectP2.width/2))-20,(rectP2.y+(rectP2.height/2))},
						(Vector2){(rectP2.x+(rectP2.width/2))-10,(rectP2.y+(rectP2.height/2)+10)}, VIOLET);
			DrawTriangle((Vector2){(rectP2.x+(rectP2.width/2))+10,(rectP2.y+(rectP2.height/2)-10)},
						(Vector2){(rectP2.x +(rectP2.width/2))+10,(rectP2.y+(rectP2.height/2)+10)},
						(Vector2){(rectP2.x +(rectP2.width/2))+20,(rectP2.y+(rectP2.height/2))},VIOLET);
			DrawText("Usa las flechas para cambiar el color de las barras!", 140, 30, 20, RAYWHITE);
			DrawText("Presiona 'Play' cuando estes listo para jugar.", 170, 50, 20, RAYWHITE);
			DrawText(TextFormat("P1: %i", puntosP1), (float)screenWidth / 20, 10, 20, RAYWHITE);
			DrawText(TextFormat("P2: %i", puntosP2), screenWidth - (float)screenWidth / 10, 10, 20, RAYWHITE);
			DrawText("Play", rectMenu.x + 30, rectMenu.y + 15, 20, RAYWHITE);
			DrawText("Exit", rectMenu4.x + 30, rectMenu4.y + 15, 20, RAYWHITE);
			EndDrawing();
		}
		// Main game loop
		while (!gameOver && !WindowShouldClose())// Detect window close button or ESC key
		{
			// Update
			//----------------------------------------------------------------------------------
			if (IsKeyDown(KEY_W))rectP1.y -= rectSpeed;
			if (IsKeyDown(KEY_S))rectP1.y += rectSpeed;
			if (IsKeyDown(KEY_UP))rectP2.y -= rectSpeed;
			if (IsKeyDown(KEY_DOWN))rectP2.y += rectSpeed;
			//----------------------------------------------------------------------------------
			// Moves Ball
			ballPosition.x += ballSpeed.x;
			ballPosition.y += ballSpeed.y;

			// Check walls collision for bouncing
			if ((ballPosition.x >= (GetScreenWidth() - ballRadius))) {
				ballPosition.x =screenWidth / 2;
				ballPosition.y =screenHeight / 2;
				puntosP1++;
				ballSpeed.x = 7.5f;
				ballSpeed.y = 6.0f;
			}
			if (ballPosition.x <= ballRadius) {
				ballPosition.x =screenWidth / 2;
				ballPosition.y =screenHeight / 2;
				puntosP2++;
				ballSpeed.x = -7.5f;
				ballSpeed.y = -6.0f;
			}
			if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius))ballSpeed.y *= -1.0f;
			// Ball only collides with rectangles once
			rect1Collision = CheckCollisionCircleRec(ballPosition, ballRadius, rectP1);
			rect2Collision = CheckCollisionCircleRec(ballPosition, ballRadius, rectP2);
			if (hasCollided == false && rect2Collision) {
				if (rectP2.y + rectP2.height / 4 >= ballPosition.y){
					if (ballSpeed.y > 0) { ballSpeed.y = -ballSpeed.y - 4; }// si esta bajando que la invierta y acelere
					if (ballSpeed.y < 0) { ballSpeed.y - 4; } // si esta subiendo que acelere
				}
				if (rectP2.y + rectP2.height / 2 >= ballPosition.y && rectP2.y + rectP2.height / 4 < ballPosition.y) {
					if (ballSpeed.y > 0) { ballSpeed.y = -ballSpeed.y-2; } // si esta bajando que la invierta y acelere
					if (ballSpeed.y < 0) { ballSpeed.y - 2; } // si esta subiendo que acelere
				}
				if (rectP2.y + rectP2.height / 2 < ballPosition.y && rectP2.y + rectP2.height / 2 + rectP2.height / 4 > ballPosition.y) {
					if (ballSpeed.y < 0) { ballSpeed.y = -ballSpeed.y + 2; } // si esta subiendo que se invierta  y acelere
					if (ballSpeed.y > 0) { ballSpeed.y + 2; } // si esta bajando acelera
				}
				if (rectP2.y + rectP2.height / 2 + rectP2.height / 4 <= ballPosition.y) {
					if (ballSpeed.y < 0) { ballSpeed.y = -ballSpeed.y + 4; }
					if (ballSpeed.y > 0) { ballSpeed.y + 4; }
				}
				ballSpeed.x = -ballSpeed.x;
				hasCollided = true;
				ballColor = rectP2Color;
			}
			if (hasCollided == false && rect1Collision) {
				if (rectP1.y + rectP1.height / 4 > ballPosition.y&&rectP1.y < ballPosition.y) {
					if (ballSpeed.y > 0) { ballSpeed.y = -ballSpeed.y - 4; }
					if (ballSpeed.y < 0) { ballSpeed.y - 4; }
				}
				if (rectP1.y + rectP1.height / 2 > ballPosition.y&&rectP1.y + rectP1.height / 4 < ballPosition.y) {
					if (ballSpeed.y > 0) { ballSpeed.y = -ballSpeed.y + -2; }
					if (ballSpeed.y < 0) { ballSpeed.y - 2; }
				}
				if (rectP1.y + rectP1.height / 2 < ballPosition.y && rectP1.y + rectP1.height / 2 + rectP1.height / 4 > ballPosition.y) {
					if (ballSpeed.y < 0) { ballSpeed.y = -ballSpeed.y + 2; }
					if (ballSpeed.y > 0) { ballSpeed.y + 2; }
				}
				if (rectP1.y + rectP1.height / 2 + rectP1.height / 4 < ballPosition.y && rectP1.y + rectP1.height > ballPosition.y) {
					if (ballSpeed.y < 0) { ballSpeed.y = -ballSpeed.y + 4; }
					if (ballSpeed.y > 0) { ballSpeed.y + 4; }
				}
				ballSpeed.x = -ballSpeed.x;
				hasCollided = true;
				ballColor = rectP1Color;
			}
			if (!(rect1Collision || rect2Collision)) {
				hasCollided = false;
			}

			if (puntosP1 >= 10 || puntosP2 >= 10)
			{
				gameOver = true;
			}

			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();

			ClearBackground(BLACK);

			DrawText(TextFormat("P1: %i", puntosP1), screenWidth / 20, 10, 20, RAYWHITE);
			DrawText(TextFormat("P2: %i", puntosP2), screenWidth - screenWidth / 10, 10, 20, RAYWHITE);
			DrawCircleV(ballPosition, ballRadius, ballColor);
			DrawRectangleRec(rectP1, rectP1Color);
			DrawRectangleRec(rectP2, rectP2Color);

			EndDrawing();
			//----------------------------------------------------------------------------------
		}

		while (gameOver && !WindowShouldClose()) {

			ballMenuPosition = GetMousePosition();
			bool menuCollision2 = CheckCollisionCircleRec(ballMenuPosition, ballRadius, rectMenu2);
			bool menuCollision3 = CheckCollisionCircleRec(ballMenuPosition, ballRadius, rectMenu3);
			if (menuCollision2&&IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				puntosP1 = 0;
				puntosP2 = 0;
				gameOver = false;
			}
			if (menuCollision3&&IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				gameMenuOn = true;
				puntosP1 = 0;
				puntosP2 = 0;
				gameOver = false;
			}
			if (puntosP1 >= 10) {
				BeginDrawing();
				ClearBackground(BLACK);
				DrawText(TextFormat("Player 1 wins!"), (screenWidth / 2) - 60, 10, 20, RAYWHITE);
			}
			if (puntosP2 >= 10) {
				BeginDrawing();
				ClearBackground(BLACK);
				DrawText(TextFormat("Player 2 wins!"), (screenWidth / 2) - 70, 10, 20, RAYWHITE);
			}

			DrawRectangleRec(rectMenu3, RED);
			DrawText(TextFormat("P1: %i", puntosP1), screenWidth / 4, 10, 20, RAYWHITE);
			DrawText(TextFormat("P2: %i", puntosP2), screenWidth - screenWidth / 4, 10, 20, RAYWHITE);
			DrawText("Back to main menu", rectMenu3.x + 10, rectMenu3.y + 15, 20, RAYWHITE);
			DrawRectangleRec(rectMenu2, RED);
			DrawText("Play again", rectMenu2.x+45, rectMenu2.y +15, 20, RAYWHITE);
			EndDrawing();
		}
	}while (!gameOver && !WindowShouldClose());
	// De-Initialization
//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
	return 0;
}

void changePlayerColor(Player &player, Player otherPlayer) {
	int colorCounter;
	bool playerPrevColor = CheckCollisionPointTriangle(menuBall.Position,
		(Vector2){(player.Position.x + (player.Size.x / 2)) - 10, (player.Position.y + (player.Size.y / 2) - 10)},
		(Vector2){(player.Position.x + (player.Size.x / 2)) - 20, (player.Position.y + (player.Size.y / 2))},
		(Vector2){(player.Position.x + (player.Size.x / 2)) - 10, (player.Position.y + (player.Size.y / 2) + 10)});
	bool playerNextColor = CheckCollisionPointTriangle(menuBall.Position,
		(Vector2){(player.Position.x + (player.Size.x / 2)) + 10, (player.Position.y + (player.Size.y / 2) - 10)},
		(Vector2){(player.Position.x + (player.Size.x / 2)) + 10, (player.Position.y + (player.Size.y / 2) + 10)},
		(Vector2){(player.Position.x + (player.Size.x / 2)) + 20, (player.Position.y + (player.Size.y / 2))});
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && playerPrevColor) {
		colorCounter--;
		if ( == colorCounterP1) { colorCounterP2--; }
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && rect2NextColor) {
		colorCounterP2++;
		if (colorCounterP2 == colorCounterP1) { colorCounterP2++; }
	}
	if (colorCounterP2 < 0) {
		colorCounterP2 = 8;
	}
	if (colorCounterP2 > 8)
	{
		colorCounterP2 = 0;
	}
	switch (colorCounterP2)
	{
	case 0:
		rectP2Color = BLUE;
		break;
	case 1:
		rectP2Color = SKYBLUE;
		break;
	case 2:
		rectP2Color = DARKBLUE;
		break;
	case 3:
		rectP2Color = MAROON;
		break;
	case 4:
		rectP2Color = YELLOW;
		break;
	case 5:
		rectP2Color = GREEN;
		break;
	case 6:
		rectP2Color = LIME;
		break;
	case 7:
		rectP2Color = BROWN;
		break;
	case 8:
		rectP2Color = DARKBROWN;
		break;
	}
};