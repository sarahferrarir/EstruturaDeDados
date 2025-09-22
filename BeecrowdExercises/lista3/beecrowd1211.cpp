// Title: Economic Phonebook

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    int N;
    while (cin >> N) {
        vector<string> v(N);
        for (int i = 0; i < N; ++i) cin >> v[i];

        sort(v.begin(), v.end());

        long long economy = 0;
        for (int i = 1; i < N; ++i) {
            int m = min(v[i - 1].size(), v[i].size());
            int k = 0;
            while (k < m && v[i - 1][k] == v[i][k]) ++k;
            economy += k;
        }
        cout << economy << endl;
    }
    return 0;
}
