// Writing a header file for paddles
#ifndef PADDLE_H
#define PADDLE_H

typedef struct {
  float x;
  float y;
  float width;
  float height;
} Paddle;

void drawRightPaddle(void);
void drawLeftPaddle(void);
void rightPaddleControl(void);
void leftPaddleControl(void);
bool leftPaddleCollision(void);
bool rightPaddleCollision(void);
#endif
