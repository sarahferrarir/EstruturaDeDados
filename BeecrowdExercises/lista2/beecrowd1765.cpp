// Title: Christmas Trapeziums

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int T, Q;
    double A, B;
    const double HEIGHT = 5.0;

    while (cin >> T && T != 0) {
        for (int i = 1; i <= T; i++) {
            cin >> Q >> A >> B;
            double area = Q * ((A + B) * HEIGHT / 2.0);
            cout << fixed << setprecision(2);
            cout << "Size #" << i << ":\n";
            cout << "Ice Cream Used: " << area << " cm2\n";
        }
        cout << "\n"; 
    }
    return 0;
}


