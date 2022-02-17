#include <iostream>
using namespace std;

//Variables
float ocena, srednia_ocen;
int n, zachowanie, suma_ocen;

int main() {
    cout << "Program sprawdza czy masz czerwony pasek na świadectwie" << endl 
        << "Podaj ocenę z zachowania: " << endl;
    cin >> zachowanie;

    cout << "Z ilu przedmiotów obliczyć średnią?" << endl;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Podaj " << i << " ocenę" << endl;
        cin >> ocena;
        suma_ocen = suma_ocen + ocena;
    }

    srednia_ocen = suma_ocen / n;
    cout << "Średnia ocen wynosi: " << srednia_ocen << endl;

    if (zachowanie >= 5 && srednia_ocen >= 4.75) 
        cout << "Dostaniesz świadectwo z czerwonym paskiem" << endl;
    else cout << "Nie dostaniesz świadectwa z paskiem" << endl;

    return 0;
}
