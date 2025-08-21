//Title: Easy Fibonacci

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N <= 0) return 0;

    int ant2 = 0; 
    int ant1 = 1;

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            cout << ant2; 
        } else if (i == 1) {
            cout << " " << ant1; 
        } else {
            int atual = ant1 + ant2; 
            cout << " " << atual;
            ant2 = ant1;
            ant1 = atual;
        }
    }

    cout << endl;
    return 0;
}
