// Title: Hard to Believe, But True

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string equation;
    while (cin >> equation) {
        size_t plusPos = equation.find('+');
        size_t equalPos = equation.find('=');

        string a = equation.substr(0, plusPos);
        string b = equation.substr(plusPos + 1, equalPos - plusPos - 1);
        string c = equation.substr(equalPos + 1);

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(c.begin(), c.end());

        int numA = stoi(a);
        int numB = stoi(b);
        int numC = stoi(c);

        if (numA + numB == numC)
            cout << "True" << endl;
        else
            cout << "False" << endl;

        if (equation == "0+0=0")
            break;
    }
    return 0;
}
