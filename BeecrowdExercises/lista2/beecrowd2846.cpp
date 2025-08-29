#include <iostream>
using namespace std;

int main() {
    long long K;
    cin >> K;
    
    long long f1 = 1;
    long long f2 = 2;
    
    while (true) {
        long long f3 = f1 + f2;
        long long gap = f3 - f2 - 1;
        
        if (K > gap) {
            K-= gap;
            f1 = f2;
            f2 = f3;
        } else {
            cout << (f2 + K) << endl;
            break;
        }
    }
    
    return 0;
}
