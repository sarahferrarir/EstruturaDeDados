#include <iostream>
using namespace std;

int main() {
    long long n;
    int instance = 1;

    while (cin >> n) {
        long long res = 1;

        for (long long i = 1; i <= n; i++) {
            res *= i;

            while (res % 10 == 0) res /= 10;

            res %= 1000000; 
        }

        cout << "Instancia " << instance << "\n";
        cout << res % 10 << "\n\n";

        instance++;
    }

    return 0;
}
