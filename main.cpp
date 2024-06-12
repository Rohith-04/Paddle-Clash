#include "ball.h"
#include "paddle.h"
#include "player.h"
#include "raylib.h"
#include "shared_file.h"
#include <cmath>
#define MAX_SCORE 5

int getWidth = 800;
int getHeight = 600;
Color bg = {68, 4, 128, 0};

float randomFloat(void) { return ((float)GetRandomValue(7, 14) / 10); }

int main(void) {
  InitWindow(getWidth, getHeight, "Pong Game");

  InitAudioDevice();
  Sound shot = LoadSound("pong.wav");
  Sound gameover = LoadSound("gameover.wav");
  srand(0);
  SetTargetFPS(120);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(bg);
    bool collisionLeft = CollisionLeft();
    bool collisionRight = CollisionRight();
    if ((collisionRight || collisionLeft)) {
      PlaySound(shot);
    }
    if (roundOver) {
      PlaySound(gameover);
      roundOver = false;
    }

    LeftControl();
    RightControl();
    UpdateBall();
    StopBall();
    updateScore();
    checkWinner();
    drawScore();
    DrawFPS(10, 10);
    DrawBall();
    DrawLeftpaddle();
    DrawRightpaddle();
    DrawLine(getWidth / 2, 0, getWidth / 2, getHeight, RAYWHITE);
    EndDrawing();
  }
  UnloadSound(shot);
  CloseAudioDevice();
  CloseWindow();
  return 0;
}
