#include "def.h"
#include "def.c"

int main(int argc, char *argv[])
{
	InitWindow(screenWidth, screenHeight, "DVD");

	SetTargetFPS(60);

	Image image = LoadImage("dvd.png");
	Texture2D texture = LoadTextureFromImage(image);
	UnloadImage(image);

	SetExitKey(KEY_ESCAPE);
	while (!WindowShouldClose()) {
		bounce(image, texture);
		renderxp(image, texture);
	}
	CloseWindow();
	return 0;
}
