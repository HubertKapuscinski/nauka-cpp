#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <filesystem>
#include <string>
#include <sys/types.h>
#include <sstream>

#ifndef WIN32
#include <unistd.h>
#endif

#ifdef WIN32
#define stat _stat
#endif

using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
using namespace std;

//Variables
string decision, changedPath, srcPath, cfgPath, Path, tp;
fstream file;
struct stat info;
struct stat result;
stringstream date;

bool PathExist(const string& s) {
    struct stat buffer;
    return (stat (s.c_str(), &buffer) == 0);
}

void sortowanie(string& path){
    try {
        //Foreach file in path
        for (auto& dirEntry : recursive_directory_iterator(path)) {
            cout << dirEntry << endl << "Last write time :";

            string filename = dirEntry.path();

            if(stat(filename.c_str(), &result)==0) {
                auto mod_time = result.st_mtime;
                cout << " " << mod_time << endl;
                date << mod_time;
                string dt = date.str();
                cout << dt << endl;
            }
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

void start() {
    cfgPath = "ImagesSorter.cfg";
    cout << "Images Sorter\n This app overwrites directory selected before. If you want to change it press y, if no then n.\n";
    cin >> decision;

    if (decision == "y") {
        cout << "Write your new directory:\n";
        cin >> changedPath;
        //Delete file
        remove("ImagesSorter.cfg");
        //Create new file
        ofstream cfg(cfgPath);
        //Print line to file
        cfg << changedPath;
        //Close file
        cfg.close();
        sortowanie(changedPath);
    }
    else if (decision == "n") {
        file.open("ImagesSorter.cfg",ios::in);
        if (file.is_open()) {
            while (getline(file, tp)) {
                Path = tp;
            }
            file.close();
        }
        sortowanie(Path);
    }
    else {
        cout << "Please, try again.\n";
    }
}

int main() {
    cfgPath = "ImagesSorter.cfg";
    if (PathExist(cfgPath) != true) {
        cout << "There was no config found. Creating...\n   Paste your path to files.\n";
        cin >> srcPath;
        //Create a file
        ofstream cfg(cfgPath);
        //Write to a file
        cfg << srcPath;
        //Close a file
        cfg.close();
    }
    start();

    return 0;
}