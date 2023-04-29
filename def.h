#ifndef _DEF_H
#define _DEF_H

#include <raylib.h>

void bounce (Image image, Texture2D texture);
void renderxp(Image image, Texture2D texture);


const int screenHeight = 450;
const int screenWidth = 800;

int img_vel = 1;

int img_dx = 1;
int img_dy = -1;

int initWidth = screenWidth / 2;
int initHeight = screenHeight / 2;

#endif /* _DEF_H */
