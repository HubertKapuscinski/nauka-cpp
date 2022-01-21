#include <iostream>
#include <fstream>
using namespace std;

int main() {
    cout << "What do u want to write into file?" << endl;
    string text;
    //Read input and write to variable
    cin >> text;

    //Create a variable File
    fstream file;
    //Open a file for a write
    file.open("file.txt", ios::out);
    //Write to a file
    file << text;
    //Close file
    file.close();

    //Read a file
    char ch;
	while (1) {
		file >> ch;
		if (file.eof()) break;
		cout << ch;
	}

    //File manipulation

    return 0;
}