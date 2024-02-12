#pragma once
#include <raylib.h>
#include <string>
#include <vector>

class Game {
private:
  int state;
  int numLetters;
  Font font;
  void DrawIntro();
  void DrawGame();
  void DebugCout();
  void SetLetterNum();
  std::string word;
  std::vector<bool> guess;
  std::vector<std::string> pastGuess;

public:
  Game();
  void Draw();
  void DrawWin();
  void DrawGameOver();
  void Update();
  void UpdateGame();
  void GetWord();
  void LetterGuess();
  void ValidateWin();
  bool IsPartOfWord(char guess);
  void UpdateIntro();
};