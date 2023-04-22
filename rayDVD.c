#include <raylib.h>
int main(int argc, char *argv[])
{
	const int screenHeight = 450;
	const int screenWidth = 800;
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
			if(initWidth+texture.width >= screenWidth || initHeight+texture.height >= screenHeight) {
				while(initWidth+texture.width!=0 || initHeight+texture.height != 0) {


					initHeight--; 
					initWidth--;

					BeginDrawing();
					DrawTexture(texture, initWidth, initHeight, WHITE);
					ClearBackground(BLACK);
					EndDrawing();
				}
			}
			else {
				initHeight++;
				initWidth++;
				BeginDrawing();
				DrawTexture(texture, initWidth, initHeight, WHITE);
				ClearBackground(BLACK);
				EndDrawing();
			}


		}
		CloseWindow();
	}
	return 0;
}
