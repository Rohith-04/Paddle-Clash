#include "../lib/ball.h"
#include "../lib/raylib.h"
#include "../lib/shared_file.h"

// Initial conditions of a ball
Ball ball = {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2, 8, 300,
             300};

void drawBall() {

  DrawCircle(ball.x - ball.size, ball.y + ball.size, ball.size, RAYWHITE);
}

void updateBall() {
  ball.x += ball.vel_x * GetFrameTime() * 1.8;
  ball.y += ball.vel_y * GetFrameTime() * 1.8;
}

// Keeps the ball inside the window
void restrictBall() {

  if (ball.y >= GetScreenHeight()) {
    ball.y = GetScreenHeight() - ball.size;
    ball.x = ball.x - ball.size;
    ball.vel_y *= -1;
  }

  if (ball.y < 0) {
    ball.y = 0;
    ball.x = ball.x + ball.size;
    ball.vel_y *= -1;
  }
}
