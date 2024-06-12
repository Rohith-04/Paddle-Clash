// shared_object.h
#ifndef SHARED_OBJECT_H
#define SHARED_OBJECT_H
#include "ball.h"
#include "paddle.h"

extern Paddle l_p;
extern Paddle r_p;
extern Ball ball;
extern int getWidth;
extern int getHeight;
extern float randomFloat(void);
extern bool roundOver;

#endif // SHARED_OBJECT_H
