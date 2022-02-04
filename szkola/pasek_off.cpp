#include <iostream>
using namespace std;

// Variables
float ocena, srednia_ocen;
int n, zachowanie, suma_ocen;

int main()
{
    cout << "\nProgram sprawdza czy masz czerwony pasek na świadectwie";

    cout << "\nSkala ocen z zachowania:";
    cout << "\nOcena wzorowa - 6";
    cout << "\nOcena bardzo dobra - 5";
    cout << "\nOcena dobra - 4";
    cout << "\nOcena poprawna - 3";
    cout << "\nOcena nieodpowiednia - 2";
    cout << "\nOcena naganna - 1";

    cout << "\nPodaj ocenę z zachowania: ";
    cin >> zachowanie;

    cout << "\nZ ilu przedmiotów obliczyć średnią?";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "\nPodaj ocenę z " << i << "przedmiotu";
        cin >> ocena;
        suma_ocen = suma_ocen + ocena;
    }

    srednia_ocen = suma_ocen / n;
    cout << "\nŚrednia ocen wynosi: " << srednia_ocen;

    if (zachowanie >= 5 && srednia_ocen >= 4.75)
        cout << "\nBrawo, dostaniesz świadectwo z czerwonym paskiem";
    else
        cout << "\nTym razem nie poszło najlepiej ale wakacje na pewno będą udane";

    return 0;
}