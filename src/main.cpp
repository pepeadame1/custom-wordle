#include "game.h"
#include <raylib.h>

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "Word Game");
  SetTargetFPS(60);
  Game game = Game();

  while (!WindowShouldClose()) {
    BeginDrawing();
    // aqui empiezo
    ClearBackground(DARKGREEN);
    game.Draw();
    game.Update();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}