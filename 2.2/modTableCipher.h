#pragma once
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class modTableCipher
{
private:
 int key;
public:
 modTableCipher()=delete;
 modTableCipher(const int& key){};
 string encrypt(const string& open_text); 
 string decrypt(const string& cipher_text); 
};
