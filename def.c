#include "def.h"

void renderxp(Image image, Texture2D texture)
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawTexture(texture, initWidth, initWidth, WHITE);
	EndDrawing();
}

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
