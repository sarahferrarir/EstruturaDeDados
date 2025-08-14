#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    while (true) {

        int X, Y;
        cin >> X >> Y;
        
        if (X > 0 && Y > 0) {
            printf("primeiro\n");
        } else if (X < 0 && Y > 0) {
            printf("segundo\n");
        } else if (X < 0 && Y < 0) {
            printf("terceiro\n");
        } else if (X > 0 && Y < 0) {
            printf("quarto\n");
        }
        if (X == 0 || Y == 0) {
            break;
        }
    }

    return 0;
}
