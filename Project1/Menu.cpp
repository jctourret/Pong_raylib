#include "Menu.h"

void initTriangles(Triangle &prevColor, Triangle &nextColor, Player player) {
	prevColor.TriBase.x=(player.Position.x+(player.Size.x/2))-10;
	prevColor.TriBase.y=(player.Position.y+(player.Size.y/2)-10);
	prevColor.TriCat1.x=(player.Position.x+(player.Size.x/2))-20;
	prevColor.TriCat1.y=(player.Position.y+(player.Size.y/2));
	prevColor.TriCat2.x=(player.Position.x+(player.Size.x/2))-10;
	prevColor.TriCat2.y=(player.Position.y+(player.Size.y/2)+10);

	nextColor.TriBase.x=(player.Position.x+(player.Size.x/2))+10;
	nextColor.TriBase.y=(player.Position.y+(player.Size.y/2)-10);
	nextColor.TriCat1.x=(player.Position.x+(player.Size.x/2))+10;
	nextColor.TriCat1.y=(player.Position.y+(player.Size.y/2)+10);
	nextColor.TriCat2.x=(player.Position.x+(player.Size.x/2)+20);
	nextColor.TriCat2.y=(player.Position.y+(player.Size.y/2));
}
void drawTriangles(Triangle prevColor,Triangle nextColor){
	DrawTriangle(prevColor.TriBase,prevColor.TriCat1,prevColor.TriCat2,VIOLET);
	DrawTriangle(nextColor.TriBase,nextColor.TriCat1,nextColor.TriCat2,VIOLET);
}
bool cursorOnTriangle(Triangle tri,Cursor cursor){
	CheckCollisionPointTriangle(menuCursor.Position, prevColor.TriBase, prevColor.TriCat1, prevColor.TriCat2);
}
void clickTriangle(Player player, Player otherPlayer){
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && cursorOnTriangle(prevColor,menuCursor)) {
		player.ColorCounter--;
		if (player.ColorCounter == otherPlayer.ColorCounter) {player.ColorCounter--;}
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && cursorOnTriangle(nextColor, menuCursor)) {
		player.ColorCounter++;
		if (player.ColorCounter == otherPlayer.ColorCounter) {player.ColorCounter++; }
	}
}
void changePlayerColor(Player player) {
	switch (player.ColorCounter)
	{
	case 0:
		player.Color = BLUE;
		break;
	case 1:
		player.Color= SKYBLUE;
		break;
	case 2:
		player.Color = DARKBLUE;
		break;
	case 3:
		player.Color = MAROON;
		break;
	case 4:
		player.Color = YELLOW;
		break;
	case 5:
		player.Color = GREEN;
		break;
	case 6:
		player.Color = LIME;
		break;
	case 7:
		player.Color = BROWN;
		break;
	case 8:
		player.Color = DARKBROWN;
		break;
	}
}