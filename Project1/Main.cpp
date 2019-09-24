#include "raylib.h"
#include "Game.h"
int main()
{
		while (gameOver && !WindowShouldClose()) {

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