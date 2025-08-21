//Title: Sequence IJ 2

#include <iostream>
using namespace std;

int main() {
    for (int I = 1; I <= 9; I += 2) {  
        for (int J = 7; J >= 5; J--) { 
            cout << "I=" << I << " J=" << J << endl;
        }
    }
    return 0;
}

