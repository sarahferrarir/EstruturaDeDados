// Title: Screws and Nuts

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    while (cin >> N) { 
        vector<int> shelf;
        
        for (int i = 0; i < N; i++) {
            int X, Y;
            cin >> X >> Y;
            for (int v = X; v <= Y; v++) {
                shelf.push_back(v);
            }
        }

        int Num;
        cin >> Num;

        vector<int> positions;
        for (int i = 0; i < (int)shelf.size(); i++) {
            if (shelf[i] == Num) {
                positions.push_back(i);
            }
        }

        if (positions.empty()) {
            cout << Num << " not found" << endl;
        } else {
            cout << Num << " found at";
            for (int p : positions) cout << " " << p;
            cout << endl;
        }
    }
    return 0;
}
