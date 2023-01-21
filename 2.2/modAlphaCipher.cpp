#include "headers/routeCipher.h"
#include <algorithm>
routeCipher::routeCipher(const int& key)
{
 columns = key;
}
std::string routeCipher::encrypt(const std::string& str)
{
 int rows = div_up(str.size(), columns);
 std::vector<std::vector<char>> table;
 for (int i = 0; i < rows; i++) {
 table.emplace_back(std::vector<char>());
 }
 int charCount = 0;
 int tableSize = columns * rows;
 for (int i = 0; i < rows; i++) {
 for (int j = 0; j < columns; j++) {
 if (charCount < str.size()) {
 table[i].push_back(str[charCount]);
 charCount++;
 } else {
 table[i].push_back(' ');
 charCount++;
 }
 }
 }
 std::string result;
 for (int i = 0; i < rows; i++)
 {
 std::reverse(table[i].begin(), table[i].end());
 for (int j = 0; j < table[i].size(); j++) {
 result.push_back(table[i][j]);
 }
 }
 return result;
}
std::string routeCipher::decrypt(const std::string& str)
{
 int rows = str.size() / columns;
 std::vector<std::vector<char>> table;
 for (int i = 0; i < rows; i++) {
 table.emplace_back(std::vector<char>());
 }
 int charCount = 0;
 int tableSize = columns * rows;
 for (int i = 0; i < rows; i++) {
 for (int j = 0; j < columns; j++) {
 if (charCount < str.size()) {
 table[i].push_back(str[charCount]);
 charCount++;
 } else {
 table[i].push_back(' ');
 charCount++;
 }
 }
 }
 std::string result;
 for (int i = 0; i < rows; i++)
 {
 std::reverse(table[i].begin(), table[i].end());
 for (int j = 0; j < table[i].size(); j++) {
 result.push_back(table[i][j]);
 }
 }
 return result;
}
int routeCipher::div_up(int x, int y)
{
 return (x - 1) / y + 1;
}
