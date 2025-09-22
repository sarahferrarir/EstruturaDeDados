// Title: Flavious Josephus Legend

#include <iostream>
using namespace std;

int josephus(int n, int k) {
    int j = 0; 
    for (int i = 2; i <= n; ++i) j = (j + k) % i;
    return j + 1;
}

int main() {
    int NC; 
    if (!(cin >> NC)) return 0;
    for (int t = 1; t <= NC; ++t) {
        int n, k; 
        cin >> n >> k;
        cout << "Case " << t << ": " << josephus(n, k) << endl;
    }
    return 0;
}
