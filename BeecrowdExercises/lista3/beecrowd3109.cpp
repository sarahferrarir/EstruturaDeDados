// Title: Desk Updates

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> desk(N + 1);
    for (int i = 1; i <= N; i++) {
        desk[i] = i; 
    }

    for (int i = 0; i < Q; i++) {
        int E;
        cin >> E;

        if (E == 1) {
            int A, B;
            cin >> A >> B;
            swap(desk[A], desk[B]);
        } else if (E == 2) {
            int A;
            cin >> A;
            int count = 0;
            int pos = A; 

            while (desk[pos] != A) {
                pos = desk[pos]; 
                count++;
            }

            cout << count << endl;
        }
    }

    return 0;
}
