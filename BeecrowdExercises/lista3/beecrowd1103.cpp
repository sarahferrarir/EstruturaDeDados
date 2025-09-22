// Title: Alarm Clock


#include <iostream>
using namespace std;

int main() {
    int H1, M1, H2, M2;

    while (true) {
        cin >> H1 >> M1 >> H2 >> M2;

        if (H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0) {
            break;
        }

        int current = H1 * 60 + M1;
        int alarm = H2 * 60 + M2;

        int min;
        if (alarm >= current) {
            min = alarm - current;
        } else {
            min = (24 * 60 - current) + alarm;
        }

        cout << min << endl;
    }

    return 0;
}

