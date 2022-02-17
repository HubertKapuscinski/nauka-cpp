#include <iostream>
#include <string>

using namespace std;

//Variables
string _name, _school;
int _age;

int main() {
  class student {
    string name, school;
    int age;

    public:

      string GetStudent() {
        string student;  
        //Todo:
          //Assign value to student

        return student;
      }
  };

  cout << "Write your name." << endl;
  cin >> _name;

  cout << "Write your age." << endl;
  cin >> _age;

  cout << "Write your school." << endl;
  cin >> _school;


}
