#include "Exit.h"
void clickButton(Cursor cursor, Rectangle rect) {
	if (CheckCollisionCircleRec(cursor.Position, cursor.Radius, rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

	}
}