// Game status and handles restart and different checkpoints in Game
#include "../lib/player.h"
#include "../lib/ball.h"
#include "../lib/paddle.h"
#include "../lib/raylib.h"
#include "../lib/shared_file.h"
#include <cstdlib>
#include <string>
#define MAX_SCORE 5

bool isPauseRight = false;
bool isPauseLeft = false;
bool roundOver = false;
bool restart = false;
int left_score = 0;
int right_score = 0;

void drawScore(void) {

  std::string left = std::to_string(left_score);
  std::string right = std::to_string(right_score);

  const char *l_score = left.c_str();
  const char *r_score = right.c_str();
  DrawText(l_score, getWidth / 4, 10, 20, RAYWHITE);
  DrawText(r_score, 3 * getWidth / 4, 10, 20, RAYWHITE);
}

int ownNumGen(void) {
  if (GetRandomValue(1, 10) % 2 == 0)
    return 1;
  if (GetRandomValue(1, 10) % 2 != 0)
    return -1;

  return 1;
}

void newRound(void) {
  isPauseLeft = false;
  isPauseRight = false;
  roundOver = false;
  restart = false;
  ball.x = (float)getWidth / 2;
  ball.y = GetRandomValue(1, getHeight);
  ball.vel_x = 300 * ownNumGen();
  ball.vel_y = 300 * ownNumGen();
  l_p.y = 240;
  r_p.y = 240;
}

void updateScore(void) {
  if (ball.x < 0) {
    ball.x = ball.y = ball.vel_x = ball.vel_y = 0;
    isPauseRight = true;
    roundOver = true;
    right_score++;
  }
  if (ball.x > GetScreenWidth()) {
    ball.x = ball.y = ball.vel_x = ball.vel_y = 0;
    isPauseLeft = true;
    roundOver = true;
    left_score++;
  }
  if ((isPauseLeft) && (left_score < MAX_SCORE) && (right_score < MAX_SCORE)) {
    DrawText("Press C to continue", getWidth / 2 - 160, getHeight / 2 - 15, 30,
             GREEN);
    if (IsKeyPressed(KEY_C) && (left_score < MAX_SCORE) &&
        (right_score < MAX_SCORE))
      newRound();
  }
  if ((isPauseRight) && (left_score < MAX_SCORE) && (right_score < MAX_SCORE)) {
    DrawText("Press C to continue", getWidth / 2 - 160, getHeight / 2 - 15, 30,
             GREEN);
    if (IsKeyPressed(KEY_C) && (left_score < MAX_SCORE) &&
        (right_score < MAX_SCORE))
      newRound();
  }
}

void checkWinner(void) {
  if (left_score >= MAX_SCORE) {
    DrawText("Left Player Wins!", getWidth / 2 - 200, getHeight / 2 - 70, 45,
             GREEN);
    DrawText("Press R to Restart", getWidth / 2 - 120, getHeight / 2 - 15, 30,
             GREEN);
    DrawText("Press Q to Quit", getWidth / 2 - 100, getHeight / 2 + 30, 30,
             GREEN);

    if (IsKeyPressed(KEY_R))
      Restart();
    if (IsKeyPressed(KEY_Q))
      CloseWindow();
  }
  if (right_score >= MAX_SCORE) {
    DrawText("Right Player Wins!", getWidth / 2 - 200, getHeight / 2 - 70, 45,
             GREEN);
    DrawText("Press R to Restart", getWidth / 2 - 120, getHeight / 2 - 15, 30,
             GREEN);
    DrawText("Press Q to Quit", getWidth / 2 - 100, getHeight / 2 + 30, 30,
             GREEN);
    if (IsKeyPressed(KEY_R))
      Restart();
    if (IsKeyPressed(KEY_Q))
      CloseWindow();
  }
}

void Restart() {
  isPauseLeft = false;
  isPauseRight = false;
  roundOver = false;
  restart = false;
  ball.x = (float)getWidth / 2;
  ball.y = GetRandomValue(1, getHeight);
  ball.vel_x = 300 * ownNumGen();
  ball.vel_y = 300 * ownNumGen();
  l_p.y = 240;
  r_p.y = 240;
  left_score = 0;
  right_score = 0;
}
