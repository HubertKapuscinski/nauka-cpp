#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

//Variables
string path = "/sys/class/backlight/amdgpu_bl0/brightness";
string cfgPath = "/home/";
string userPath;
string source;
string brightness;
string decision;
string username = getlogin();
fstream brFile;
fstream cfgFile;
int value;

void error() {
    cout << endl << "Error occured while trying to open cfg file." << endl;
    exit(0);
}

int main() {
    cfgPath += username;
    cfgPath += "/.config/brightness/brightness.conf";

    cfgFile.open(cfgPath);
    if (cfgFile.good() == false) {
        cout << "There was no config file found. Creating." << endl
             << "Write your path to brightness configuration file." << endl 
             << "(Default = " << path << ")" << endl;
        cin >> userPath;
        
        system("mkdir ~/.config/brightness");
        system("touch ~/.config/brightness/brightness.conf");

        cfgFile.open(cfgPath);
        if (cfgFile.good() == false) error();
        else {
            cfgFile << userPath;
            cfgFile.close();
            cout << "Config file created succesfuly." << endl;
        }
    }

    cout << "Current brightness value:";
    
    cfgFile.open(cfgPath, ios::in | ios::out);
    if (cfgFile.is_open()) {
        getline(cfgFile, path);
        brFile.close();
    }
    else error();

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
                    brFile.close();
                    brFile.open(path);
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
