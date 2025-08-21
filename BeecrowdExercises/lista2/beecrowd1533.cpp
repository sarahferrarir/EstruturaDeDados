// Title: Detective Watson

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<int> suspects(N);
        
        for (int i = 0; i < N; i++) {
            cin >> suspects[i];
        }

        int highest = -1, second_highest = -1;
        int index_highest = -1, index_second = -1;

        for (int i = 0; i < N; i++) {
            if (suspects[i] > highest) {
                second_highest = highest;
                index_second = index_highest;

                highest = suspects[i];
                index_highest = i;
            } else if (suspects[i] > second_highest) {
                second_highest = suspects[i];
                index_second = i;
            }
        }

        cout << index_second + 1 << endl; 
    }
    return 0;
}
