#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a,b,c,p,ph;

    cout << "Program oblicza pole trójkąta wg wzoru Herona.\nPodaj długość 1 boku" << endl;
    cin >> a;
    cout << "Podaj długość 2 boku" << endl;
    cin >> b;
    cout << "Podaj długość 3 boku" << endl;
    cin >> c;

    if (a + b > c && a + c > b && b + c > a) {
        p = (a + b + c) / 2;
        ph = sqrt(p*(p-a)*(p-b)*(p-c));
        cout << "Pole wynosi: " << ph << "." << endl;
    }
    else cout << "Z podanych długości boków nie można skonstruować trójkąta";

    return 0;
}