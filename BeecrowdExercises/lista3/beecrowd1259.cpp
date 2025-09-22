// Title: Even and Odd

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> even;
    vector<int> odd;

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        if (number % 2 == 0) {
            even.push_back(number);
        } else {
            odd.push_back(number);
        }
    }

    sort(even.begin(), even.end());

    sort(odd.rbegin(), odd.rend());

    for (int evenList : even) {
        cout << evenList << endl;
    }

    for (int oddList : odd) {
        cout << oddList << endl;
    }

    return 0;
}