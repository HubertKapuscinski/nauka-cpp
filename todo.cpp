#include <iostream>
#include <ostream>
#include <string>
#include <fstream>

using namespace std;

//Variables
string usage;
int taskNumber;

void start() {
  cout << "Todo - Usage:\nl: list tasks\na: add task\nd: delete task" << endl;
  cin >> usage;
}

int main() {
  class tasks {
    string name ;
    string description;
    string date;
    int number;
    bool isDone;
    bool isExpired;

  public:
    void del(string taskName);
    void add(string taskName);
  };

  if (usage == "l"|| usage == "L") {

  }
  else if (usage == "d" || usage == "D") {
    
  }
  else if (usage == "q" || usage == "Q") {
    
  }
  else if (usage == "a" || usage == "A") {
    
  }

  return 0;
}
