// Title: KiloMan))

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T; 
    cin >> T;  
    
    while (T--) {
        int S;
        cin >> S;  
        
        vector<int> heights(S);
        for (int i = 0; i < S; i++) {
            cin >> heights[i];
        }
        
        string jumps;
        cin >> jumps;  

        int hits = 0;
        for (int i = 0; i < S; i++) {
            if ((jumps[i] == 'S' && (heights[i] == 1 || heights[i] == 2)) ||
                (jumps[i] == 'J' && heights[i] > 2)) {
                hits++;
            }
        }
        
        cout << hits << endl;
    }
    
    return 0;
}
