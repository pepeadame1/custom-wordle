#pragma once
#include <string>

class FileHandler {
private:
  int test;

public:
  FileHandler();
  std::string GetWord(int wordLen);
};