#include "lib/ball.h"
#include "lib/paddle.h"
#include "lib/player.h"
#include "lib/raylib.h"
#include "lib/shared_file.h"
#include <cmath>
#define MAX_SCORE 5

int getWidth = 800;
int getHeight = 600;
Color bg = {68, 4, 128, 0};

float randomFloat(void) { return ((float)GetRandomValue(7, 14) / 10); }

int main(void) {
  InitWindow(getWidth, getHeight, "Paddle-Clash");

  InitAudioDevice();
  Sound shot = LoadSound("assets/pong.wav");
  Sound gameover = LoadSound("assets/gameover.wav");
  srand(0);
  SetTargetFPS(120);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(bg);
    bool collisionLeft = leftPaddleCollision();
    bool collisionRight = rightPaddleCollision();
    if ((collisionRight || collisionLeft)) {
      PlaySound(shot);
    }
    if (roundOver) {
      PlaySound(gameover);
      roundOver = false;
    }

    leftPaddleControl();
    rightPaddleControl();
    updateBall();
    restrictBall();
    updateScore();
    checkWinner();
    drawScore();
    DrawFPS(10, 10);
    drawBall();
    drawLeftPaddle();
    drawRightPaddle();
    DrawLine(getWidth / 2, 0, getWidth / 2, getHeight, RAYWHITE);
    EndDrawing();
  }
  UnloadSound(shot);
  CloseAudioDevice();
  CloseWindow();
  return 0;
}
