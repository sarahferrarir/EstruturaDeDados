// Title: Flíper

#include <iostream>
using namespace std;

int main() {
    int P, R;
    cin >> P >> R; 
    if (P == 1) {
        if (R == 1)
            cout << "A" << endl;
        else
            cout << "B" << endl;
    } else {
        cout << "C" << endl;
    }

    return 0;
}

