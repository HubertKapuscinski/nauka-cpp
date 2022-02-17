#include <iostream>
#include <fstream>

using namespace std;

//Variables
string path = "/sys/class/backlight/amdgpu_bl0/brightness";
string source;
string brightness;
string decision;
fstream brFile;
int value;

int main() {
    cout << "Current brightness value:";
    
    brFile.open(path, ios::in | ios::out);
    if (brFile.good() == true) {
        getline(brFile, brightness);
        cout << " " << brightness << endl
             << "Min = 0, Max = 255" << endl;
        brFile.close();

        while (true) {
            cout << "Enter brightness value to change or q to quit." << endl;
            cin >> decision;

            if (decision == "q" || decision == "Q") exit(0);
            else {
                value = stoi(decision);
            
                if (value > 255 || value < 0) cout << "Error, wrong value." << endl;
                else {
                    remove("/sys/class/backlight/amdgpu_bl0c");
                    brFile.open(path);
                    brFile << value;
                    getline(brFile, brightness);
                    brFile.close();
                    
                    cout << endl << "Current brightness value: " << brightness << endl;
                }
            }
        }
    } 
    else cout << endl << "Error opening file." << endl;
    return 0;
}
