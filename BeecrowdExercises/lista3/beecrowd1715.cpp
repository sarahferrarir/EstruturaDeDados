// Title: Handball

#include <iostream>
using namespace std;

int main() {
    int N, M;

    while (cin >> N >> M) {
        int count = 0; 

        for (int i = 0; i < N; i++) {
            bool goalsInAll = true; 

            for (int j = 0; j < M; j++) {
                int goals;
                cin >> goals;

                if (goals == 0) {
                    goalsInAll = false; 
                }
            }

            if (goalsInAll) {
                count++; 
            }
        }

        cout << count << endl;
    }

    return 0;
}
