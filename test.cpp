#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <filesystem>
#include <cstring>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>
using namespace std;

int main() {
    struct stat attrib;                 //1. create a file attribute structure
    stat("/home/hubertk/.wallpaper1", &attrib);         //2. get the attributes of afile.txt
    auto clock = gmtime(&(attrib.st_mtime)); //3. Get the last modified time and
                                        // put it into the time structure
    cout << clock << endl;
}