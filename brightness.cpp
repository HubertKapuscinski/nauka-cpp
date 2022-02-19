#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>

using namespace std;

//Variables
string path = "/sys/class/backlight/amdgpu_bl0/brightness";
string cfgPath = "/home/";
string username = getlogin();
string userPath;
string source;
string brightness;
string decision;
fstream brFile;
fstream cfgFile;
int value;
int argVal;

void error(int errVal) {
    switch (errVal) {
        case 1:
            cout << "Error occured while trying to open cfg file." << endl;
            break;
        case 2:
            cout << "Error while reading arguments." << endl 
                 << "Max arguments is 1 - brightness value." << endl;
            break;
        case 3:
            cout << "Error occured while opening brightness file." << endl;
            break;
        case 4:
            cout << "Error. Max value = 255 and min value = 0." << endl;
            break;
        default:
            cout << "Unhandled exception." << endl;
            break;
    }
    exit(0);
}

void openCfgFile() {
    cfgFile.open(cfgPath, ios::in | ios::out);
    if (cfgFile.is_open()) {
        getline(cfgFile, path);
        cfgFile.close();
    }
    else error(1);
}

int main(int argc, char **argValue) {
    //Complete
    cfgPath += username;
    cfgPath += "/.config/brightness/brightness.cfg";
    
    //Run with args
    if (argc == 2) {
        sscanf (argValue[1],"%d",&argVal);
        if (argVal > 255 || argVal < 0) error(4);

        openCfgFile();
        remove("/sys/class/backlight/amdgpu_bl0/brightness");
        brFile.open(path, ios::in | ios::out);
        if (brFile.is_open()) {
            brFile << argVal;
            brFile.close();
        }
        else error(3);

        exit(0);
    }
    else if (argc > 2) error(2);

    //Creating cfg file
    cfgFile.open(cfgPath);
    if (cfgFile.good() == false) {
        cout << "There was no config file found. Creating." << endl
             << "Write your path to brightness configuration file." << endl 
             << "(Default = " << path << ")" << endl;
        cin >> userPath;
        
        system("mkdir ~/.config/brightness/");
        system("touch ~/.config/brightness/brightness.cfg");

        cout << cfgPath << endl;

        cfgFile.open(cfgPath);
        if (cfgFile.is_open() == false) error(1);
        else {
            cfgFile << userPath;
            cfgFile.close();
            cout << "Config file created succesfuly." << endl;
        }
    }

    cout << "Current brightness value:";
    
    openCfgFile();

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
                    remove("/sys/class/backlight/amdgpu_bl0/brightness");
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
