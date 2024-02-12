#include "FileHandler.h"
#include "game.h"
#include <iostream>
#include <raylib.h>
#include <string>

Game::Game() {
  numLetters = 5;
  state = 0;
  font = LoadFontEx("Font/Roboto-Regular.ttf", 64, 0, 0);
}

void Game::DrawIntro() {
  char title[] = "WORD GAME";
  char subTitle[] = "enter number of letters you want for the word game";
  int titleSize = 64;
  int subtitleSize = 20;
  Vector2 textSizeTitle = MeasureTextEx(font, title, titleSize, 5);
  Vector2 textSizeSubtitle = MeasureTextEx(font, subTitle, subtitleSize, 5);
  DrawTextEx(font, title, {GetScreenWidth() / 2 - (textSizeTitle.x / 2), GetScreenHeight() / 2 - textSizeTitle.y / 2}, titleSize, 5, WHITE);
  DrawTextEx(font, subTitle, {GetScreenWidth() / 2 - (textSizeSubtitle.x / 2), (float)(GetScreenHeight() - 100)}, subtitleSize, 5, WHITE);
}

void Game::DrawGame() {
  int step = (GetScreenWidth() - 100) / word.length();

  for (int i = 0; i < word.length(); i++) {
    char letter[10];
    sprintf(letter, "%c", word[i]);
    if (guess[i]) {
      DrawTextEx(font, letter, {(float)50 + step * i, (float)GetScreenHeight() / 3}, 40, 5, WHITE);
    } else {
      DrawTextEx(font, "?", {(float)50 + step * i, (float)GetScreenHeight() / 3}, 40, 5, WHITE);
    }
  }
  // Vector2 textSizeSubtitle = MeasureTextEx(font, subTitle, subtitleSize, 5);
}

void Game::DebugCout() {
  std::cout << word << std::endl;
  std::cout << "current guess" << std::endl;
  for (int i = 0; i <= guess.size(); i++) {
    std::cout << guess[i] << " ";
  }
  std::cout << std::endl;
}

void Game::SetLetterNum() {
}

void Game::Draw() {
  switch (state) {
  case 0:
    DrawIntro();
    break;
  case 2:
    DrawGame();
  case 3:
    DrawWin();
  case 4:
    DrawGameOver();

  default:
    // DrawIntro();
    break;
  }
}

void Game::DrawWin() {
}

void Game::DrawGameOver() {
}

void Game::Update() {
  switch (state) {
  case 0:
    UpdateIntro();
    break;
  case 1:
    GetWord();
    break;
  case 2:
    UpdateGame();
    break;
  case 3:
    std::cout << "won" << std::endl;
    break;

  default:
    break;
  }
}

void Game::UpdateGame() {
  LetterGuess();
}

void Game::GetWord() {
  FileHandler fh = FileHandler();
  word = fh.GetWord(numLetters);
  for (int i = 0; i < word.length(); i++) {
    guess.push_back(false);
    // guess[i] = false;
  }

  state = 2;
}

void Game::LetterGuess() {
  char key = GetCharPressed();
  if (isalpha(key)) {
    for (int i = 0; i < word.length(); i++) {
      if (word[i] == key) {
        guess[i] = true;
      }
    }
    ValidateWin();
  }
}

void Game::ValidateWin() {
  bool hasLettersLeft = false;
  for (int i = 0; i <= guess.size(); i++) {
    if (guess[i] == false) {
      hasLettersLeft = true;
    }
  }
  if (!hasLettersLeft) {
    state = 3;
  }
}

void Game::UpdateIntro() {
  switch (GetKeyPressed()) {
  case KEY_ONE:
    numLetters = 1;
    state = 1;
    break;

  case KEY_TWO:
    numLetters = 2;
    state = 1;
    break;
  case KEY_THREE:
    numLetters = 3;
    state = 1;
    break;
  case KEY_FOUR:
    numLetters = 4;
    state = 1;
    break;
  case KEY_FIVE:
    numLetters = 5;
    state = 1;
    break;
  case KEY_SIX:
    numLetters = 6;
    state = 1;
    break;
  case KEY_SEVEN:
    numLetters = 7;
    state = 1;
    break;
  case KEY_EIGHT:
    numLetters = 8;
    state = 1;
    break;
  case KEY_NINE:
    numLetters = 9;
    state = 1;
    break;
  default:
    break;
  }
}
