#include <raylib.h>

const int screenHeight = 450;
const int screenWidth = 800;

int img_vel = 1;

int img_dx = 1;
int img_dy = -1;

int initWidth = screenWidth / 2;
int initHeight = screenHeight / 2;


void bounce(Image image, Texture2D texture)
{
	int area = texture.height * texture.width;
	initWidth += (img_dx * img_vel);
	initHeight += (img_dy * img_vel);

	if(initWidth + texture.width > screenWidth) {
		initWidth = screenWidth - area / 2 * 1.2;
		img_dx = -1;
	}
	else if(initWidth < 0) {
		initWidth = initWidth;
		img_dx = 1;
	}

	if(initHeight < 0) {
		initHeight = initHeight;
		img_dy = 1;
	}
	else if(initHeight + texture.height > screenHeight) {
		initHeight = screenHeight - area / 2 * 1.2;
		img_dy = -1;
	}

}

void renderxp(Image image, Texture2D texture)
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawTexture(texture, initWidth, initWidth, WHITE);
	EndDrawing();
}

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
