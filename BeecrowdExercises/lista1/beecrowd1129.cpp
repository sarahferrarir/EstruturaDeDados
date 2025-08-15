#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) { 
        for (int i = 0; i < N; i++) {
            int A, B, C, D, E;
            cin >> A >> B >> C >> D >> E;

            int alternatives[] = {A, B, C, D, E};
            char letters[] = {'A', 'B', 'C', 'D', 'E'};
            int selected = -1;
            int countBlack = 0;

            for (int j = 0; j < 5; j++) {
                if (alternatives[j] <= 127) {
                    countBlack++;
                    if (countBlack > 1) {
                        selected = -1;
                        break;
                    }
                    selected = j;
                }
            }

            if (countBlack == 1) {
                cout << letters[selected] << endl;
            } else {
                cout << "*" << endl;
            }
        }
    }
    return 0;
}
