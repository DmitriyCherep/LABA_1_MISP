#pragma once
#include <vector>
#include <string>
class routeCipher
{
 private:
 int columns;
 int div_up(int x, int y);
 public:
 routeCipher()=delete;
 routeCipher(const int& key);
 std::string encrypt(const std::string& open_text);
 std::string decrypt(const std::string& cipher_text);
};
