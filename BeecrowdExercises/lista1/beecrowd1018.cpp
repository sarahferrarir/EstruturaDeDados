#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    cout << N << endl;
    int notes, notes1, notes2, notes3, notes4, notes5, notes6;

    notes = N / 100;
    N = N % 100;
    notes1 = N / 50;
    N = N % 50;
    notes2 = N / 20;
    N = N % 20;
    notes3 = N / 10;
    N = N % 10;
    notes4 = N / 5;
    N = N % 5;
    notes5 = N / 2;
    N = N % 2;
    notes6 = N / 1;
    N = N % 1;

    cout << notes << " nota(s) de R$ 100,00" << endl;
    cout << notes1 << " nota(s) de R$ 50,00" << endl;
    cout << notes2 << " nota(s) de R$ 20,00" << endl;
    cout << notes3 << " nota(s) de R$ 10,00" << endl;
    cout << notes4 << " nota(s) de R$ 5,00" << endl;
    cout << notes5 << " nota(s) de R$ 2,00" << endl;
    cout << notes6 << " nota(s) de R$ 1,00" << endl;

    return 0;
}
