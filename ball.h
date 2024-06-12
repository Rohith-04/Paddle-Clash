// A header file for BAll
#ifndef BALL_H
#define BALL_H

#include "raylib.h"

struct Ball {

  float x;
  float y;
  float size;
  float vel_x;
  float vel_y;
};

void DrawBall(void);
void UpdateBall(void);
void StopBall(void);

#endif
