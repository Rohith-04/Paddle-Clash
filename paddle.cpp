#include "paddle.h"
#include "raylib.h"
#include "shared_file.h"

Paddle l_p = {10, 240, 10, 120};
Paddle r_p = {780, 240, 10, 120};

Color paddle_color = {234, 242, 5, 0};

void DrawRightpaddle() {
  DrawRectangle(r_p.x, r_p.y, r_p.width, r_p.height, YELLOW);
}

void DrawLeftpaddle() {
  DrawRectangle(l_p.x, l_p.y, l_p.width, l_p.height, YELLOW);
}

void RightControl() {
  if (IsKeyDown(KEY_UP)) {
    r_p.y -= 900 * GetFrameTime();
  }
  if (IsKeyDown(KEY_DOWN)) {
    r_p.y += 900 * GetFrameTime();
  }
}

void LeftControl() {
  if (IsKeyDown(KEY_W)) { // Controls for both left paddle and roght paddle
    l_p.y -= 900 * GetFrameTime();
  }
  if (IsKeyDown(KEY_S)) {
    l_p.y += 900 * GetFrameTime();
  }
}

bool CollisionRight() {
  if (CheckCollisionCircleRec(
          (Vector2){ball.x, ball.y}, ball.size,
          (Rectangle){r_p.x, r_p.y, r_p.width, r_p.height})) {
    ball.vel_x *= -1;
    if (IsKeyDown(KEY_UP)) {
      if (ball.vel_y > 0)
        ball.vel_y *= -1 * randomFloat();
    }
    if (IsKeyDown(KEY_DOWN)) {
      if (ball.vel_y < 0)
        ball.vel_y *= -1 * randomFloat();
    }
    ball.x = ball.x - ball.size; // Collision checker for left right paddle
    ball.y = ball.y - ball.size;
    return true;
  }
  return false;
}

bool CollisionLeft() {
  if (CheckCollisionCircleRec(
          (Vector2){ball.x, ball.y}, ball.size,
          (Rectangle){l_p.x, l_p.y, l_p.width, l_p.height})) {
    ball.vel_x *= -1;
    if (IsKeyDown(KEY_W)) {
      if (ball.vel_y > 0)
        ball.vel_y *= -1 * randomFloat();
    }
    if (IsKeyDown(KEY_S)) {
      if (ball.vel_y < 0)
        ball.vel_y *= -1 * randomFloat();
    }
    ball.x = ball.x + ball.size; // Collision checker for left right paddle
    ball.y = ball.y + ball.size;
    return true;
  }
  return false;
}
