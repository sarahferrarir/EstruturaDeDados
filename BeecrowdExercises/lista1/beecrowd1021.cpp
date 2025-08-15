#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double N;
    cin >> N;

    int notes100 = N / 100;
    N = N - (notes100 * 100);
    int notes50 = N / 50;
    N = N - (notes50 * 50);
    int notes20 = N / 20;
    N = N - (notes20 * 20);
    int notes10 = N / 10;
    N = N - (notes10 * 10);
    int notes5 = N / 5;
    N = N - (notes5 * 5);
    int notes2 = N / 2;
    N = N - (notes2 * 2);

    N = N * 100; 

    int coins1 = N / 100;
    N = N - (coins1 * 100);
    int coins50 = N / 50;
    N = N - (coins50 * 50);
    int coins25 = N / 25;
    N = N - (coins25 * 25);
    int coins10 = N / 10;
    N = N - (coins10 * 10);
    int coins05 = N / 5;
    N = N - (coins05 * 5);
    int coins01 = N;

    cout << "NOTAS:" << endl;
    cout << notes100 << " nota(s) de R$ 100.00" << endl;
    cout << notes50 << " nota(s) de R$ 50.00" << endl;
    cout << notes20 << " nota(s) de R$ 20.00" << endl;
    cout << notes10 << " nota(s) de R$ 10.00" << endl;
    cout << notes5 << " nota(s) de R$ 5.00" << endl;
    cout << notes2 << " nota(s) de R$ 2.00" << endl;

    cout << "MOEDAS:" << endl;
    cout << coins1 << " moeda(s) de R$ 1.00" << endl;
    cout << coins50 << " moeda(s) de R$ 0.50" << endl;
    cout << coins25 << " moeda(s) de R$ 0.25" << endl;
    cout << coins10 << " moeda(s) de R$ 0.10" << endl;
    cout << coins05 << " moeda(s) de R$ 0.05" << endl;
    cout << coins01 << " moeda(s) de R$ 0.01" << endl;

    return 0;
}
