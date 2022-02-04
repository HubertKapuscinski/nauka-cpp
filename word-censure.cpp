#include <iostream>
using namespace std;

//Variables
string censored_words[] = {"Kurka", "Cholipka"};
string text;
int start = 0;
int length = text.length();
string::size_type pos = censored_words.find(text);

int main() {
    cout << "Paste text to check for bad words." << endl;
    cin >> text;

    return 0;
}