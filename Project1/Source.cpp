#include "raylib.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

	Vector2 ballMenuPosition = { -100.0f,-100.0f };
	Color ballMenuColor = DARKBLUE;
	Vector2 ballPosition = { (float)screenWidth / 2,(float)screenHeight / 2 };
	Rectangle rectMenu;
	rectMenu.width = 100;
	rectMenu.height = 50;
	rectMenu.x = 350;
	rectMenu.y = 350;
	Rectangle rectMenu2;
	rectMenu2.width = 200;
	rectMenu2.height = 50;
	rectMenu2.x = 300;
	rectMenu2.y = 250;
	Rectangle rectMenu3;
	rectMenu3.width = 200;
	rectMenu3.height = 50;
	rectMenu3.x = 300;
	rectMenu3.y = 350;
	Rectangle rectP1;
	rectP1.width = 8;
	rectP1.height = 75;
	rectP1.x = (float)screenWidth / 20;
	rectP1.y = (float)screenHeight / 2;
	Rectangle rectP2;
	rectP2.width = 8;
	rectP2.height = 75;
	rectP2.x = screenWidth - (float)screenWidth / 20;
	rectP2.y = (float)screenHeight / 2;
	Color rectP1Color = BLUE;
	Color rectP2Color = MAROON;
	Color ballColor = WHITE;
	Vector2 ballSpeed = { 7.5f,6.0f };
	int rectSpeed = 8;
	int ballRadius = 10;
	int puntosP1 = 0;
	int puntosP2 = 0;
	int colorCounterP1 = 0;
	int colorCounterP2 = 4;
	bool rect1Collision = false;
	bool rect2Collision = false;
	bool rect1PrevColor = false;
	bool rect1NextColor = false;
	bool rect2PrevColor = false;
	bool rect2NextColor = false;
	bool hasCollided = false;
	bool gameMenuOn = true;
	bool GameOver = false;
	Vector2 TriBase = { 5,5 };
	Vector2 TriCat1 = { 5,5 };
	Vector2 TriCat2 = { 5,5 };

	SetTargetFPS(60);// Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------
	do {
			while (gameMenuOn && !WindowShouldClose())
			{
				ballMenuPosition = GetMousePosition();

				BeginDrawing();
				ClearBackground(BLACK);
				DrawText("Usa las flechas para cambiar el color de las barras!", 140, 30, 20, RAYWHITE);
				DrawText("Presiona 'Play' cuando estes listo para jugar.", 170, 50, 20, RAYWHITE);
				DrawText(TextFormat("P1: %i", puntosP1), (float)screenWidth / 20, 10, 20, RAYWHITE);
				DrawText(TextFormat("P2: %i", puntosP2), screenWidth - (float)screenWidth / 10, 10, 20, RAYWHITE);
				DrawCircleV(ballPosition, ballRadius - 5, MAROON);
				DrawRectangleRec(rectP1, rectP1Color);
				DrawRectangleRec(rectP2, rectP2Color);
				DrawRectangleRec(rectMenu, RED);
				DrawText("Play", rectMenu.x + 30, rectMenu.y + 15, 20, RAYWHITE);
				DrawTriangle((Vector2) { (rectP1.x + (rectP1.width / 2)) - 10, (rectP1.y + (rectP1.height / 2) - 10) },
					(Vector2) {
					(rectP1.x + (rectP1.width / 2)) - 20, (rectP1.y + (rectP1.height / 2))
				},
					(Vector2) {
					(rectP1.x + (rectP1.width / 2)) - 10, (rectP1.y + (rectP1.height / 2) + 10)
				}, VIOLET);
				DrawTriangle((Vector2) { (rectP1.x + (rectP1.width / 2)) + 10, (rectP1.y + (rectP1.height / 2) - 10) },
					(Vector2) {
					(rectP1.x + (rectP1.width / 2)) + 10, (rectP1.y + (rectP1.height / 2) + 10)
				},
					(Vector2) {
					(rectP1.x + (rectP1.width / 2)) + 20, (rectP1.y + (rectP1.height / 2))
				}, VIOLET);
				DrawTriangle((Vector2) { (rectP2.x + (rectP2.width / 2)) - 10, (rectP2.y + (rectP2.height / 2) - 10) },
					(Vector2) {
					(rectP2.x + (rectP2.width / 2)) - 20, (rectP2.y + (rectP2.height / 2))
				},
					(Vector2) {
					(rectP2.x + (rectP2.width / 2)) - 10, (rectP2.y + (rectP2.height / 2) + 10)
				}, VIOLET);
				DrawTriangle((Vector2) { (rectP2.x + (rectP2.width / 2)) + 10, (rectP2.y + (rectP2.height / 2) - 10) },
					(Vector2) {
					(rectP2.x + (rectP2.width / 2)) + 10, (rectP2.y + (rectP2.height / 2) + 10)
				},
					(Vector2) {
					(rectP2.x + (rectP2.width / 2)) + 20, (rectP2.y + (rectP2.height / 2))
				}, VIOLET);
				EndDrawing();

				bool menuCollision = CheckCollisionCircleRec(ballMenuPosition, ballRadius, rectMenu);
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && menuCollision) {
					gameMenuOn = false;
				}
				rect1PrevColor = CheckCollisionPointTriangle(ballMenuPosition,
					(Vector2) {
					(rectP1.x + (rectP1.width / 2)) - 10, (rectP1.y + (rectP1.height / 2) - 10)
				},
					(Vector2) {
					(rectP1.x + (rectP1.width / 2)) - 20, (rectP1.y + (rectP1.height / 2))
				},
						(Vector2) {
						(rectP1.x + (rectP1.width / 2)) - 10, (rectP1.y + (rectP1.height / 2) + 10)
					});

				rect1NextColor = CheckCollisionPointTriangle(ballMenuPosition,
					(Vector2) {
					(rectP1.x + (rectP1.width / 2)) + 10, (rectP1.y + (rectP1.height / 2) - 10)
				},
					(Vector2) {
					(rectP1.x + (rectP1.width / 2)) + 10, (rectP1.y + (rectP1.height / 2) + 10)
				},
						(Vector2) {
						(rectP1.x + (rectP1.width / 2)) + 20, (rectP1.y + (rectP1.height / 2))
					});

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && rect1PrevColor) {
					colorCounterP1--;
					if (colorCounterP1 == colorCounterP2) { colorCounterP1--; }
				}
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && rect1NextColor) {
					colorCounterP1++;
					if (colorCounterP1 == colorCounterP2) { colorCounterP1++; }
				}
				if (colorCounterP1 < 0) {
					colorCounterP1 = 10;
				}
				if (colorCounterP1 > 10)
				{
					colorCounterP1 = 0;
				}
				switch (colorCounterP1)
				{
				case 0:
					rectP1Color = BLUE;
					break;
				case 1:
					rectP1Color = SKYBLUE;
					break;
				case 2:
					rectP1Color = DARKBLUE;
					break;
				case 3:
					rectP1Color = RED;
					break;
				case 4:
					rectP1Color = MAROON;
					break;
				case 5:
					rectP1Color = ORANGE;
					break;
				case 6:
					rectP1Color = YELLOW;
					break;
				case 7:
					rectP1Color = GREEN;
					break;
				case 8:
					rectP1Color = LIME;
					break;
				case 9:
					rectP1Color = BROWN;
					break;
				case 10:
					rectP1Color = DARKBROWN;
					break;
				}

				rect2PrevColor = CheckCollisionPointTriangle(ballMenuPosition,
					(Vector2) {
					(rectP2.x + (rectP2.width / 2)) - 10, (rectP2.y + (rectP2.height / 2) - 10)
				},
					(Vector2) {
					(rectP2.x + (rectP2.width / 2)) - 20, (rectP2.y + (rectP2.height / 2))
				},
						(Vector2) {
						(rectP2.x + (rectP2.width / 2)) - 10, (rectP2.y + (rectP2.height / 2) + 10)
					});
				rect2NextColor = CheckCollisionPointTriangle(ballMenuPosition,
					(Vector2) {
					(rectP2.x + (rectP2.width / 2)) + 10, (rectP2.y + (rectP2.height / 2) - 10)
				},
					(Vector2) {
					(rectP2.x + (rectP2.width / 2)) + 10, (rectP2.y + (rectP2.height / 2) + 10)
				},
						(Vector2) {
						(rectP2.x + (rectP2.width / 2)) + 20, (rectP2.y + (rectP2.height / 2))
					});

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && rect2PrevColor) {
					colorCounterP2--;
					if (colorCounterP2 == colorCounterP1) { colorCounterP2--; }
				}
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && rect2NextColor) {
					colorCounterP2++;
					if (colorCounterP1 == colorCounterP2) { colorCounterP1--; }
				}
				if (colorCounterP2 < 0) {
					colorCounterP2 = 10;
				}
				if (colorCounterP2 > 10)
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
					rectP2Color = RED;
					break;
				case 4:
					rectP2Color = MAROON;
					break;
				case 5:
					rectP2Color = ORANGE;
					break;
				case 6:
					rectP2Color = YELLOW;
					break;
				case 7:
					rectP2Color = GREEN;
					break;
				case 8:
					rectP2Color = LIME;
					break;
				case 9:
					rectP2Color = BROWN;
					break;
				case 10:
					rectP2Color = DARKBROWN;
					break;
				}
			}
			// Main game loop
			while (!GameOver && !WindowShouldClose())// Detect window close button or ESC key
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
					ballPosition.x = (float)screenWidth / 2;
					ballPosition.y = (float)screenHeight / 2;
					puntosP1++;
					ballSpeed.x = 7.5f;
					ballSpeed.y = 6.0f;
				}
				if (ballPosition.x <= ballRadius) {
					ballPosition.x = (float)screenWidth / 2;
					ballPosition.y = (float)screenHeight / 2;
					puntosP2++;
					ballSpeed.x = -7.5f;
					ballSpeed.y = -6.0f;
				}
				if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius))ballSpeed.y *= -1.0f;
				// Check Rectangle's collision with walls
				if ((rectP1.y + rectP1.height) >= GetScreenHeight()) rectP1.y = GetScreenHeight() - rectP1.height;
				else if (rectP1.y <= 0) rectP1.y = 0;
				if ((rectP2.y + rectP2.height) >= GetScreenHeight()) rectP2.y = GetScreenHeight() - rectP2.height;
				else if (rectP2.y <= 0) rectP2.y = 0;
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
				}
				if (!(rect1Collision || rect2Collision)) {
					hasCollided = false;
				}

				if (puntosP1 >= 10 || puntosP2 >= 10)
				{
					GameOver = true;
				}

				// Draw
				//----------------------------------------------------------------------------------
				BeginDrawing();

				ClearBackground(BLACK);

				DrawText(TextFormat("P1: %i", puntosP1), (float)screenWidth / 20, 10, 20, RAYWHITE);
				DrawText(TextFormat("P2: %i", puntosP2), screenWidth - (float)screenWidth / 10, 10, 20, RAYWHITE);
				DrawText(TextFormat("Press I to reset point"), ((float)screenWidth / 2) - 120, 10, 20, RAYWHITE);
				DrawCircleV(ballPosition, ballRadius, ballColor);
				DrawRectangleRec(rectP1, rectP1Color);
				DrawRectangleRec(rectP2, rectP2Color);


				EndDrawing();
				//----------------------------------------------------------------------------------
			}

			while (GameOver && !WindowShouldClose()) {

				ballMenuPosition = GetMousePosition();
				bool menuCollision2 = CheckCollisionCircleRec(ballMenuPosition, ballRadius, rectMenu2);
				bool menuCollision3 = CheckCollisionCircleRec(ballMenuPosition, ballRadius, rectMenu3);
				if (menuCollision2&&IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					puntosP1 = 0;
					puntosP2 = 0;
					GameOver = false;
				}
				if (menuCollision3&&IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					gameMenuOn = true;
					puntosP1 = 0;
					puntosP2 = 0;
					GameOver = false;
				}
				if (puntosP1 >= 10) {
					BeginDrawing();
					ClearBackground(BLACK);
					DrawText(TextFormat("Player 1 wins!"), ((float)screenWidth / 2) - 60, 10, 20, RAYWHITE);
				}
				if (puntosP2 >= 10) {
					BeginDrawing();
					ClearBackground(BLACK);
					DrawText(TextFormat("Player 2 wins!"), ((float)screenWidth / 2) - 70, 10, 20, RAYWHITE);
				}

				DrawRectangleRec(rectMenu3, RED);
				DrawText(TextFormat("P1: %i", puntosP1), (float)screenWidth / 4, 10, 20, RAYWHITE);
				DrawText(TextFormat("P2: %i", puntosP2), screenWidth - (float)screenWidth / 4, 10, 20, RAYWHITE);
				DrawText("Back to main menu", rectMenu.x - 40, rectMenu.y + 15, 20, RAYWHITE);
				DrawRectangleRec(rectMenu2, RED);
				DrawText("Play again", rectMenu.x, rectMenu.y - 85, 20, RAYWHITE);
				EndDrawing();
			}
	}while (!GameOver && !WindowShouldClose());
	// De-Initialization
//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
	return 0;
}