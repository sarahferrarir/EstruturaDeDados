// Title: Where is the Marble?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q, cases = 1;

    while (cin >> N >> Q) {
        if (N == 0 && Q == 0) break;

        vector<int> marbles(N);
        for (int i = 0; i < N; i++) {
            cin >> marbles[i];
        }

        sort(marbles.begin(), marbles.end()); 

        cout << "CASE# " << cases++ << ":\n";

        for (int i = 0; i < Q; i++) {
            int query;
            cin >> query;

            int pos = -1;
            for (int j = 0; j < N; j++) {
                if (marbles[j] == query) {
                    pos = j + 1; 
                    break;       
                }
            }

            if (pos != -1) {
                cout << query << " found at " << pos << "\n";
            } else {
                cout << query << " not found\n";
            }
        }
    }

    return 0;
}
