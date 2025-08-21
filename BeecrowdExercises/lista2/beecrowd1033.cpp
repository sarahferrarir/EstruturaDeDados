//Title: How Many Calls?

#include<iostream>
using namespace std;

int main() {
    long long n;
    int b;
    int caseNum = 1;

    while (cin >> n >> b) {
        if (n == 0 && b == 0) break;

        if (n == 0) {
            cout << "Case " << caseNum++ << ": " << n << " " << b << " 1" << endl;
            continue;
        }
        if (n == 1) {
            cout << "Case " << caseNum++ << ": " << n << " " << b << " 1" << endl;
            continue;
        }    

        long long ini2 = 1 % b; 
        long long ini1 = 1 % b; 
        long long atual; 

        for (long long i = 2; i <= n; i++) {
            atual = (ini1 + ini2 + 1) % b; 
            ini2 = ini1;
            ini1 = atual;
        }

        cout << "Case " << caseNum++ << ": " << n << " " << b << " " << atual << endl;
    }

    return 0;
}
