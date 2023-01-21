#include <iostream>
#include <limits>
#include "headers/routeCipher.h"
bool isValid(const std::string& s)
{
 for(unsigned i = 0; i < s.size(); i++) {
 if (!((int)s[i] > 31 && (int)s[i] < 128))
 return false;
 }
 return true;
}
int main()
{
 int key;
 std::string text;
 unsigned op;
 std::cout << "Key: ";
 std::cin >> key;
 while(std::cin.fail()) {
 std::cout << "Can only receive integers. Key: ";
 std::cin.clear();
 std::cin.ignore(256,'\n');
 std::cin >> key;
 }
 routeCipher cipher(key);
 do {
 std::cout<<"Operation (0-exit, 1-encrypt, 2-decrypt): ";
 std::cin>>op;
 if (op > 2) {
 std::cout<<"Illegal operation\n";
 } else if (op >0) {
 std::cout<<"Text: ";
 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\
n');
 std::getline(std::cin, text);
 if (isValid(text)) {
 if (op==1) {
 std::cout<< "Encrypted text: " << cipher.encrypt(text)
<<std::endl;
 } else {
 std::cout<< "Decrypted text: " << cipher.decrypt(text)
<<std::endl;
 }
 } else {
 std::cout<<"Operation aborted: invalid text\n";
 }
 }
 } while (op!=0);
 return 0;
}
