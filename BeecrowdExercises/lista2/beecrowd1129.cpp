//Title: Optical Reader

#include <iostream>
using namespace std;

int main() {
    float N;
    while (cin >> N && N != 0) { 
        for (int i = 0; i < N; i++) {
            int A, B, C, D, E;
            cin >> A >> B >> C >> D >> E;

            int alt[] = {A, B, C, D, E};
            char let[] = {'A', 'B', 'C', 'D', 'E'};
            int sel = -1;
            int countBlack = 0;

            for (int j = 0; j < 5; j++) {
                if (alt[j] <= 127) {
                    countBlack++;
                    if (countBlack > 1) {
                        sel= -1;
                        break;
                    }
                    sel = j;
                }
            }

            if (countBlack == 1) {
                cout << let[sel] << endl;
            } else {
                cout << "*" << endl;
            }
        }
    }
    return 0;
}
