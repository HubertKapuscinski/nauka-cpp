#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <filesystem>
#include <cstring>

using namespace std;

//Variables
    string decision, changedPath, srcPath, cfgPath, Path, tp, pathToCD;
    //Dates
        string year, month, monthDay;
    struct stat t_stat;
    fstream file;
    const char* cPath;

bool PathExist(const string& s) {
    struct stat buffer;
    return (stat (s.c_str(), &buffer) == 0);
}

void sorting(string& path){
    try {
        //Foreach file in path
        for (auto& dirEntry : filesystem::recursive_directory_iterator(path)) {
            //Add data to variables
            cPath = dirEntry.path().c_str();
            stat(cPath, &t_stat);
            struct tm * timeinfo = localtime(&t_stat.st_ctime);

            cout << dirEntry.path() << endl;
            printf("File time and date: %s", asctime(timeinfo));

            //Dates
            year = timeinfo->tm_year;
            month = timeinfo->tm_mon;
            monthDay = timeinfo->tm_mday;
            pathToCD = path + "/" + year;

            filesystem::create_directory(pathToCD);
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

int main() {
    cfgPath = "ImagesSorter.cfg";

    if (PathExist(cfgPath) != true) {
        cout << "There was no config found. Creating...\n Paste your path to files.\n";
        cin >> srcPath;
        //Create a file
        ofstream cfg(cfgPath);
        //Write to a file
        cfg << srcPath;
        //Close a file
        cfg.close();
    }

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
        sorting(changedPath);
    }
    else if (decision == "n") {
        file.open("ImagesSorter.cfg", ios::in);
        if (file.is_open()) {
            while (getline(file, tp)) Path = tp;
            file.close();
        }
        sorting(Path);
    }
    else cout << "Please, try again.\n";

    return 0;
}