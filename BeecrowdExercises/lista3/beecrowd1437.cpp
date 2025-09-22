// Title: Turn Left!

#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        string comando;
        cin >> comando;

  
        int dir = 0;

        for (char c : comando) {
            if (c == 'D') {
                dir = (dir + 1) % 4;
            } else if (c == 'E') {
                dir = (dir + 3) % 4; 
            }
        }

        if (dir == 0) cout << 'N' << endl;
        else if (dir == 1) cout << 'L' << endl;
        else if (dir == 2) cout << 'S' << endl;
        else cout << 'O' << endl;
    }
    return 0;
}
