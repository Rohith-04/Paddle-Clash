#include "ball.h"
#include "raylib.h"
#include "shared_file.h"

Ball ball = {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2, 8, 300,
             300};

void DrawBall() {

  DrawCircle(ball.x - ball.size, ball.y + ball.size, ball.size, RAYWHITE);
}

void UpdateBall() {
  ball.x += ball.vel_x * GetFrameTime() * 1.8; // Updating ball velocities
  ball.y += ball.vel_y * GetFrameTime() * 1.8;
}

void StopBall() {

  if (ball.y >= GetScreenHeight()) {
    ball.y = GetScreenHeight() - ball.size;
    ball.x = ball.x - ball.size; // Keeping the ball inside the dabba
    ball.vel_y *= -1;
  }

  if (ball.y < 0) {
    ball.y = 0; // Keeping the ball inside the dabba
    ball.x = ball.x + ball.size;
    ball.vel_y *= -1;
  }
}
