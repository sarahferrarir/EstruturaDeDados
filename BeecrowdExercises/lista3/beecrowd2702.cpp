// Title: Hard Choice

#include <iostream>
using namespace std;

int main() {
    int Ca, Ba, Pa; 
    int Cr, Br, Pr; 
    cin >> Ca >> Ba >> Pa;
    cin >> Cr >> Br >> Pr;

    int insatisfeitos = 0; 

    if (Cr > Ca) insatisfeitos += Cr - Ca;
    if (Br > Ba) insatisfeitos += Br - Ba;
    if (Pr > Pa) insatisfeitos += Pr - Pa;

    cout << insatisfeitos << endl;

    return 0;
}
