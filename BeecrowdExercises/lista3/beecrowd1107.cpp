// Title: Laser Sculpture
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A, C;
    while (true) {
        cin >> A >> C;
        if (A == 0 && C == 0) {
            break;
        }

        vector<int> X(C);
        for (int i = 0; i < C; i++) { 
            cin >> X[i];
        }

        int ans = A - X[0];
        for (int i = 1; i < C; i++) {   
            if (X[i-1] > X[i]) {
                ans += X[i-1] - X[i];
            }
        }

        cout << ans << endl;  
    }

    return 0;
}
