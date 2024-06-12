#include "raylib.h"
#include <stdio.h>

typedef struct { /*Ball structure*/
  int x;
  int y;
  float size;
  float vel_x;
  float vel_y;
} Ball;

typedef struct { // Paddle structure
  int x;
  int y;
  int width;
  int height;
} Paddle;

int main() {

  InitWindow(800, 600, "PingPong");
  SetTargetFPS(120);

  Ball ball = {(int)GetScreenWidth() / 2.0f, (int)GetScreenHeight() / 2.0f, 8,
               300, 300}; // Initialising the
  Paddle left_paddle = {10, (int)GetScreenHeight() / 2.0f - 60, 10,
                        140}; // objects with values
  Paddle right_paddle = {780, (int)GetScreenHeight() / 2.0f - 60, 10, 140};

  while (!WindowShouldClose()) {

    if (CheckCollisionCircleRec((Vector2){ball.x, ball.y}, ball.size,
                                (Rectangle){left_paddle.x, left_paddle.y,
                                            left_paddle.width,
                                            left_paddle.height})) {
      ball.vel_x *= -1;
      ball.x = ball.x + ball.size; // Collision checker for left paddle
      ball.y = ball.y + ball.size;
      // ball.vel_y *= -1; //Will deal later
    }
    if (CheckCollisionCircleRec((Vector2){ball.x, ball.y}, ball.size,
                                (Rectangle){right_paddle.x, right_paddle.y,
                                            right_paddle.width,
                                            right_paddle.height})) {
      ball.vel_x *= -1;
      ball.x = ball.x - ball.size; // Collision checker for right paddle
      ball.y = ball.y - ball.size;
      // ball.vel_y *= -1; //will deal later
    }
    if (ball.x < 0) {
      ball.vel_x = 0;
      ball.x = ball.y = 0;
      ball.vel_y = 0; // Game checker for left side i.e right goal
      printf("Right player wins!\n");
      return 1;
    }
    if (ball.x > GetScreenWidth()) {
      ball.vel_x = 0;
      ball.vel_y = 0; // Game checker for right side i.e left goal
      ball.x = ball.y = GetScreenWidth();
      printf("Left player wins!\n");
      return 1;
    }

    ball.x += ball.vel_x * GetFrameTime(); // Updating ball velocities
    ball.y += ball.vel_y * GetFrameTime();

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

    if (IsKeyDown(KEY_W)) { // Controls for both left paddle and roght paddle
                            // will add a seperate window as
      left_paddle.y -=
          400 *
          GetFrameTime(); // instruction guide for the newer version of the game
    }
    if (IsKeyDown(KEY_S)) {
      left_paddle.y += 400 * GetFrameTime();
    }
    if (IsKeyDown(KEY_UP)) {
      right_paddle.y -= 400 * GetFrameTime();
    }
    if (IsKeyDown(KEY_DOWN)) {
      right_paddle.y += 400 * GetFrameTime();
    }

    BeginDrawing();
    ClearBackground(WHITE); // Drawing the shapes
    DrawFPS(10, 10);

    DrawCircle(ball.x - ball.size, ball.y + ball.size, ball.size, BLACK);
    DrawRectangle(left_paddle.x, left_paddle.y, left_paddle.width,
                  left_paddle.height, BLACK);
    DrawRectangle(right_paddle.x, right_paddle.y, right_paddle.width,
                  right_paddle.height, BLACK);
    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(),
             BLACK);

    EndDrawing();
  }

  return 0;
}
