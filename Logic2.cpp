#include <iostream>
using namespace std;

bool is_palindrome(string text) {
  string reversed_text = "";
  
  for (int i = text.size() - 1; i >= 0; i--)
    reversed_text += text[i];
  
  if (reversed_text == text) return true;
  
  return false;
}

int main() {
  std::cout << is_palindrome("madam") << "\n";
  std::cout << is_palindrome("ada") << "\n";
  std::cout << is_palindrome("lovelace") << "\n";
}