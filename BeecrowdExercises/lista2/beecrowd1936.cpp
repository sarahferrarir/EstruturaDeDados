//Title: Factorial

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int smallestAmount(int N) {
    vector<int> factorials = {1};
    int i = 1;
    while (true) {
        int factorial = factorials.back() * i;
        if (factorial > N)
            break;
        factorials.push_back(factorial);
        i++;
    }

    vector<int> dp(N + 1, numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int f : factorials) {
            if (f > i)
                break;
            dp[i] = min(dp[i], dp[i - f] + 1);
        }
    }

    return dp[N];
}

int main() {
    int N;
    cin >> N;

    cout << smallestAmount(N) << endl;

    return 0;
}

