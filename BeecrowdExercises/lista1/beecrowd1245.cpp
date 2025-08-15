#include <iostream>

using namespace std;

int main() {
    int N;
    while (cin >> N) {  
        int e[61] = {0};  
        int d[61] = {0};   
        
        for (int i = 0; i < N; i++) {
            int l;
            char foot;
            cin >> l >> foot;
            
            if (foot == 'E') {
                e[l]++;  
            } else {
                d[l]++;   
            }
        }
        
        int pairs = 0;
        for (int i = 30; i <= 60; i++) {  
            pairs += min(e[i], d[i]);  
        }
        
        cout << pairs << endl;
    }

    return 0;
}
