// Title: Bakugan

#include <iostream>
using namespace std;

int first_triple(const int v[], int n) {
    for (int i = 2; i < n; i++) {
        if (v[i] == v[i-1] && v[i-1] == v[i-2]) {
            return i; 
        }
    }
    return -1; 
}

int main() {

    int R;
    while (cin >> R && R) {
        int M[10], L[10];
        int sumM = 0, sumL = 0;

        for (int i = 0; i < R; i++) {
            cin >> M[i];
            sumM += M[i];
        }
        for (int i = 0; i < R; i++) {
            cin >> L[i];
            sumL += L[i];
        }

        int mIdx = first_triple(M, R);
        int lIdx = first_triple(L, R);

        if (mIdx != -1 && (lIdx == -1 || mIdx < lIdx)) {
            sumM += 30;
        } else if (lIdx != -1 && (mIdx == -1 || lIdx < mIdx)) {
            sumL += 30;
        }


        if (sumM > sumL) {
            cout << "M" << endl;
        } else if (sumL > sumM) {
            cout << "L" << endl;
        } else {
            cout << "T" << endl;
        }
    }

    return 0;
}
