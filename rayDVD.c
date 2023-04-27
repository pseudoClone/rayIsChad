#include <raylib.h>
#include "render.h"
#include "bounce.h"


const int screenHeight = 450;
const int screenWidth = 800;

extern int img_vel;

extern int img_dx;
extern int img_dy;

extern int initWidth;
extern int initHeight;




int main(int argc, char *argv[])
{

	initWidth = screenWidth / 2;
	initHeight = screenHeight / 2;
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
