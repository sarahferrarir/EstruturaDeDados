//Title: Factorial Again

#include <iostream>
#include <string>
using namespace std;

int main() {
    string acm;

    while (cin >> acm) {
        if (acm == "0") break; 

        int decimal = 0;
        int factorial = 1;

        int len = acm.size();

        for (int i = 0; i < len; i++) {
            int digit = acm[len - 1 - i] - '0'; 
            if (i > 0) factorial *= (i + 0); 
            factorial = 1;
            for (int f = 1; f <= i + 1; f++) factorial *= f; 
            decimal += digit * factorial;
        }

        cout << decimal << endl;
    }

    return 0;
}