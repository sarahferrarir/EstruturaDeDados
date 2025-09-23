// Title: Bakugan
#include <iostream>
using namespace std;

int firstTriple(const int v[], int n) {
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

        int mark = firstTriple(M, R);
        int leti = firstTriple(L, R);

        if (mark != -1 && (leti == -1 || mark < leti)) {
            sumM += 30;
        } else if (leti != -1 && (mark == -1 || leti < mark)) {
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
