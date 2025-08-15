#include <iostream>
using namespace std;

int calls;

int fibo(int n) {
    if (n <= 1) {
        return n;
    }

    calls += 2;
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int X;
        cin >> X;
        calls = 0;

        if (X == 0) {
            cout << "fib(" << X << ") = " << calls << " calls = 0" << endl;
            continue;
        }
        if (X == 1) {
            cout << "fib(" << X << ") = " << calls << " calls = 1" << endl;
            continue;
        }

        int result = fibo(X);
        cout << "fib(" << X << ") = " << calls << " calls = " << result << endl;
    }

    return 0;
}