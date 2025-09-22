// Title: Exchanging Cards

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A, B;
    while (cin >> A >> B) {
        if (A == 0 && B == 0) break;

        vector<int> a(A), b(B);
        for (int i = 0; i < A; i++) cin >> a[i];
        for (int j = 0; j < B; j++) cin >> b[j];

        int i = 0, j = 0;
        int unicosA = 0, unicosB = 0;

        while (i < A && j < B) {
            if (a[i] == b[j]) {
                int v = a[i];
                while (i < A && a[i] == v) i++;
                while (j < B && b[j] == v) j++;
            } else if (a[i] < b[j]) {
                int v = a[i];
                unicosA++;
                while (i < A && a[i] == v) i++;
            } else { 
                int v = b[j];
                unicosB++;
                while (j < B && b[j] == v) j++;
            }
        }
        while (i < A) {
            int v = a[i];
            unicosA++;
            while (i < A && a[i] == v) i++;
        }
        while (j < B) {
            int v = b[j];
            unicosB++;
            while (j < B && b[j] == v) j++;
        }

        cout << min(unicosA, unicosB) << endl;
    }
    return 0;
}
