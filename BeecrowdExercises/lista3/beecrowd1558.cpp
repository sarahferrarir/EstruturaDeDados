// Title: Sum of two Squares

#include <iostream>
#include <cmath>
using namespace std;

bool isSquare(int x) {
    int r = (int) sqrt(x);
    return r * r == x;
}

int main() {
    int n;
    while (cin >> n) {           
        if (n < 0) {
            cout << "NO" << endl;
            continue;
        }
        bool ok = false;
        for (int a = 0; a * a <= n; a++) {
            int b2 = n - a * a;
            if (isSquare(b2)) { 
                ok = true;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
}

    }
    return 0;
}
