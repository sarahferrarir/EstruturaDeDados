// Title: Handball

#include <iostream>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M) { 
        int count = 0;

        for (int i = 0; i < N; i++) {
            bool regular = true; 
            for (int j = 0; j < M; j++) {
                int goals;
                cin >> goals;
                if (goals == 0) {
                    regular = false; 
                }
            }
            if (regular) {
                count++; 
            }
        }
        cout << count << endl;
    }
    return 0;
}
