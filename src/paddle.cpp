#include "../lib/paddle.h"
#include "../lib/raylib.h"
#include "../lib/shared_file.h"

Paddle l_p = {10, 240, 10, 120};
Paddle r_p = {780, 240, 10, 120};

Color paddle_color = {234, 242, 5, 0};

void drawRightPaddle() {
  DrawRectangle(r_p.x, r_p.y, r_p.width, r_p.height, YELLOW);
}

void drawLeftPaddle() {
  DrawRectangle(l_p.x, l_p.y, l_p.width, l_p.height, YELLOW);
}

void rightPaddleControl() {
  if (IsKeyDown(KEY_UP)) {
    r_p.y -= 900 * GetFrameTime();
  }
  if (IsKeyDown(KEY_DOWN)) {
    r_p.y += 900 * GetFrameTime();
  }
}

void leftPaddleControl() {
  if (IsKeyDown(KEY_W)) {
    l_p.y -= 900 * GetFrameTime();
  }
  if (IsKeyDown(KEY_S)) {
    l_p.y += 900 * GetFrameTime();
  }
}

bool rightPaddleCollision() {
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
    ball.x = ball.x - ball.size;
    ball.y = ball.y - ball.size;
    return true;
  }
  return false;
}

bool leftPaddleCollision() {
  if (CheckCollisionCircleRec(
          (Vector2){ball.x, ball.y}, ball.size,
          (Rectangle){l_p.x, l_p.y, l_p.width, l_p.height})) {
    ball.vel_x *= -1;
    if (IsKeyDown(KEY_W)) { // Pushes ball up if the paddle is going up
      if (ball.vel_y > 0)
        ball.vel_y *= -1 * randomFloat();
    } else if (IsKeyDown(
                   KEY_S)) { // Pushes ball down if the paddle is going down
      if (ball.vel_y < 0)
        ball.vel_y *= -1 * randomFloat();
    } else {
      ball.vel_y *= randomFloat(); // No change in directon in y
    }

    // Updating positions to make collisions look good
    ball.x = ball.x + ball.size;
    ball.y = ball.y + ball.size;
    return true;
  }
  return false;
}
