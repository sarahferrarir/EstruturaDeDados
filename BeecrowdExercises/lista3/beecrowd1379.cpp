//Title: Mean Median Problem

#include <iostream>
using namespace std;

int main() {
    int B, C;

    
    for (cin >> B >> C; B != 0 || C != 0; cin >> B >> C) {
       
        int A = 2 * B - C;
        
        cout << A << endl;
    }

    return 0;
}
