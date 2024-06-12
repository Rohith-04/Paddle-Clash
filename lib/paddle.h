// Writing a header file for paddles
#ifndef PADDLE_H
#define PADDLE_H

typedef struct {
  float x;
  float y;
  float width;
  float height;
} Paddle;

void DrawRightpaddle(void);
void DrawLeftpaddle(void);
void RightControl(void);
void LeftControl(void);
bool CollisionRight(void);
bool CollisionLeft(void);
#endif
