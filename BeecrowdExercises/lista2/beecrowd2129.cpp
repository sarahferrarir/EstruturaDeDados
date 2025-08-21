// Factorial

#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int MAXN = 1000000;
    vector<int> last_digit(MAXN + 1);
    last_digit[0] = 1;

    for (int i = 1; i <= MAXN; i++) {
        long long temp = last_digit[i - 1] * i;

        while (temp % 10 == 0) temp /= 10;

        last_digit[i] = temp % 10; 
    }

    long long n;
    int instance = 1;
    while (cin >> n) {
        cout << "Instancia " << instance++ << "\n";
        cout << last_digit[n] << "\n\n";
    }
}
