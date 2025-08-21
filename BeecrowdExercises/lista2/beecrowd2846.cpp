// Title: Fibonot

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K;
    cin >> K;

    vector<long long> fib = {1, 1};
    while (fib.back() <= 2 * K) { 
        fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
    }

    int count = 0;  
    long long num = 1;
    size_t fib_index = 0;
    long long fib_current = fib[fib_index];

    while (true) {
        if (num == fib_current) {
            fib_index++;
            fib_current = fib_index < fib.size() ? fib[fib_index] : -1;
        } else {
            count++;
            if (count == K) {
                cout << num << endl;
                break;
            }
        }
        num++;
    }

    return 0;
}
