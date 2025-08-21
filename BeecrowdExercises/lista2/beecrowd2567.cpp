// Title: Virus

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    while (cin >> N) {  
        vector<int> ages(N);
        for (int i = 0; i < N; i++)
            cin >> ages[i];

        sort(ages.begin(), ages.end());

        int lethality = 0;
        int i = 0, j = N - 1;
        while (i < j) {
            lethality += ages[j] - ages[i];
            i++;
            j--;
        }

        cout << lethality << endl;
    }
    return 0;
}
