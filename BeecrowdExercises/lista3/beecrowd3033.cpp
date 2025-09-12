// Title: Big Word

#include <iostream>
#include <string>
using namespace std;

int main() {
    string palavra;

    while (cin >> palavra) {
        if (palavra.length() >= 10) {
            cout << "palavrao" << endl;
        } else {
            cout << "palavrinha" << endl;
        }
    }

    return 0;
}
