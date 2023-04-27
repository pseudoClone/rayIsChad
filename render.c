#include <raylib.h>
#include "render.h"

void renderxp(Image image, Texture2D texture)
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawTexture(texture, initWidth, initWidth, WHITE);
	EndDrawing();
}
