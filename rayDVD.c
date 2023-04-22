#include <raylib.h>
int main(int argc, char *argv[])
{
	const int screenHeight = 450;
	const int screenWidth = 800;
	InitWindow(screenWidth, screenHeight, "DVD Logo");
	SetTargetFPS(60);


	Image image = LoadImage("/home/diethyl/dvd.png");
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
			if(initWidth >= screenWidth || initHeight >= screenHeight) {
				while(initWidth!=0 || initHeight != 0) {


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
