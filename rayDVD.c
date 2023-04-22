#include <raylib.h>

const int screenHeight = 450;
const int screenWidth = 800;


static void inline renderxp(Texture2D texture, int initHeight, int initWidth)
{

	BeginDrawing();
	DrawTexture(texture, initWidth, initHeight, WHITE);
	ClearBackground(BLACK);
	EndDrawing();
}

int main(int argc, char *argv[])
{
	
	
	InitWindow(screenWidth, screenHeight, "DVD Logo");
	SetTargetFPS(60);


	Image image = LoadImage("dvd.png");
	Texture2D texture = LoadTextureFromImage(image);
	UnloadImage(image);
	image = LoadImageFromTexture(texture);


	UnloadTexture(texture);
	texture = LoadTextureFromImage(image);
	UnloadImage(image);

	SetExitKey(KEY_ESCAPE);

	int initWidth = screenWidth/2;
	int initHeight = screenHeight/2;


	while(!WindowShouldClose()){
		ClearBackground(BLACK);
		while(1) {
			initHeight--;
			initWidth--;
			BeginDrawing();
			DrawTexture(texture, initWidth, initHeight, WHITE);
			ClearBackground(BLACK);
			EndDrawing();
			if(initWidth - (texture.width/2) >= screenWidth) {
				initWidth = screenWidth - texture.width;
				renderxp(texture, initHeight, initWidth);

			}
			else if((initWidth - texture.width) < 0) {
				initWidth = initWidth;
				renderxp(texture, initHeight, initWidth);
			}
			if((initHeight - texture.height) < 0) {
				initHeight = initHeight;
				renderxp(texture, initHeight, initWidth);
			}
			else if((initHeight - texture.height/2) >= screenHeight) {
				initHeight = screenHeight - texture.height;
				renderxp(texture, initHeight, initWidth);
			}


		}
		CloseWindow();
	}
	return 0;
}
