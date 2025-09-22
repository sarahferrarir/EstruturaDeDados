// Title: Distância entre Amigos

#include <iostream>
#include <vector>
using namespace std;

int main() {

    int N;
    cin >> N;
    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    long long maxA = A[1] - 1;
    long long maxDist = 0;        

    for (int j = 2; j <= N; ++j) {
        long long dist = maxA + (A[j] + j);
        if (dist > maxDist) maxDist = dist;
        if (A[j] - j > maxA) maxA = A[j] - j;
    }

    cout << maxDist << endl;
    return 0;
}



