#include <iostream>
using namespace std;

int main() {
    int rok;
    cout << "Program sprawdza czy możesz kandydować na prezydenta.\nPodaj rok urodzenia." << endl;
    cin >> rok;
    if (rok <= 1987) cout << "możesz kandydować na prezydenta." << endl;
    else cout << "Nie możesz jeszcze kandydować na prezydenta." << endl;
}