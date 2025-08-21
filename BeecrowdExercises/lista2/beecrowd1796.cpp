// Title: Brazilian Economy 

#include <iostream>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    int countOk = 0;
    
    for (int i = 0; i < Q; i++) {
        int opinion;
        cin >> opinion;
        if (opinion == 0)
            countOk++;
    }

    if (countOk > Q / 2)
        cout << "Y" << endl;
    else
        cout << "N" << endl;

    return 0;
}
