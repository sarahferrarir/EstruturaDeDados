// Title: Queen
#include <iostream>
#include <cmath> 
using namespace std;

int queen_moves(int X1, int Y1, int X2, int Y2) {
    if (X1 == X2 && Y1 == Y2) {
        return 0;
    } else if (X1 == X2 || Y1 == Y2 || abs(X1 - X2) == abs(Y1 - Y2)) {
        return 1;
    } else {
        return 2;
    }
}

int main() {
    int X1, Y1, X2, Y2;

    while (true) {
        cin >> X1 >> Y1 >> X2 >> Y2;
        if (X1 == 0 && Y1 == 0 && X2 == 0 && Y2 == 0) {
            break;
        }
        cout << queen_moves(X1, Y1, X2, Y2) << endl;
    }

    return 0;
}
