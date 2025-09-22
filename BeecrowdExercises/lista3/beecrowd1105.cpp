// Title: Sub-Prime

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int B, N;
    while (cin >> B >> N) {
        if (B == 0 && N == 0) break;

        vector<int> saldo(B + 1);
        for (int i = 1; i <= B; i++) cin >> saldo[i];

        for (int i = 0; i < N; i++) {
            int D, C, V;
            cin >> D >> C >> V;
            saldo[D] -= V;
            saldo[C] += V;
        }

        bool ok = true;
        for (int i = 1; i <= B; i++) {
            if (saldo[i] < 0) {
                ok = false;
                break;
            }
        }

       if (ok) {
           cout << "S" << endl;
       } else {
           cout << "N" << endl;
}

    }
    return 0;
}
