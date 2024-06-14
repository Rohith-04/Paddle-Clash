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

void drawBall(void);
void updateBall(void);
void restrictBall(void);

#endif
