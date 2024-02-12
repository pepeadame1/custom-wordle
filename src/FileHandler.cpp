#include "FileHandler.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

FileHandler::FileHandler() {
  test = 10;
}

string FileHandler::GetWord(int wordLen) {
  vector<string> words;
  string line;
  ifstream file("assets/words_alpha.txt");
  if (file.is_open()) {
    while (getline(file, line)) {
      if (line.length() == wordLen) {
        words.push_back(line);
      }
    }
  }
  int randomIndex = rand() % words.size();

  cout << words[randomIndex] << endl;
  return words[randomIndex];
}