#include "raylib.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	// Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------
		// Main game loop
		while (!gameOver && !WindowShouldClose())// Detect window close button or ESC key
		{

			// Ball only collides with rectangles once
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