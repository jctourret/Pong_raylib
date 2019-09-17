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
		// Main game loop
		while (!gameOver && !WindowShouldClose())// Detect window close button or ESC key
		{
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