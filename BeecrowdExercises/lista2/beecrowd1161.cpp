//Title: Factorial Sum 

#include <iostream>
using namespace std;

int main() {
    long long factorial[21];  
    factorial[0] = 1;

    for (int i = 1; i <= 20; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    int M, N;
    while (cin >> M >> N) {
        cout << factorial[M] + factorial[N] << endl;
    }

    return 0;
}