#include "Exit.h"
#include "raylib.h"
struct Cursor {
	Vector2 Position;
	Color Color = WHITE;
	Vector2 Speed = { 7.5f,6.0f };
	int Radius = 10;
};

Cursor menuCursor;
void clickButton(Cursor cursor, Rectangle rect) {
	if (CheckCollisionCircleRec(cursor.Position, cursor.Radius, rect)&&IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

	}
}