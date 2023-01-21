#include <iostream>
#include <cctype>
#include "headers/modAlphaCipher.h"
#include <Windows.h>
using namespace std;
bool isValid(const wstring& s)
{
 for(unsigned i = 0; i < s.size(); i++) {
 if (!(((int)s[i] > 191 && (int)s[i] < 224) || ((int)s[i] == 168)))
 return false;
 }
 return true;
}
int main(int argc, char **argv)
{
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
 wstring key;
 wstring text;
 unsigned op;
 wcout << L"Cipher ready. Input key: ";
 wcin >> key;
 if (!isValid(key)) {
 wcerr<<L"key not valid\n";
 return 1;
 }
 wcout<<L"Key loaded\n";
 modAlphaCipher cipher(key);
 do {
 wcout<<L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-
decrypt): ";
 wcin>>op;
 if (op > 2) {
 wcout<<L"Illegal operation\n";
 } else if (op >0) {
 wcout<<L"Cipher ready. Input text: ";
 wcin>>text;
 if (isValid(text)) {
 if (op==1) {
 wcout<< L"Encrypted text: " << cipher.encrypt(text)
<<endl;
 } else {
 wcout<< L"Decrypted text: " << cipher.decrypt(text)
<<endl;
 }
 } else {
 wcout<<L"Operation aborted: invalid text\n";
 }
 }
 } while (op!=0);
 return 0;
}

