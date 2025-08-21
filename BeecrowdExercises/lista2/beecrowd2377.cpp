//Title: Pedágio

#include <iostream>
using namespace std;

int main() {
    int L, D, K, P;
    cin >> L >> D;
    cin >> K >> P;

    int custo_km = L * K;
    int pedagios = (L / D) * P;

    int total = custo_km + pedagios;

    cout << total << endl;

    return 0;
}
