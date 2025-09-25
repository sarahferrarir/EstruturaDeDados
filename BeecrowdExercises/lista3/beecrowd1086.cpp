// Title: The Club Ballroom
#include <bits/stdc++.h>
using namespace std;

int ballroom(int side, int other, int L, vector<int> planks) {
    if ((other * 100) % L != 0) return -1;
    int rows = (other * 100) / L;

    sort(planks.begin(), planks.end());
    multiset<int> s(planks.begin(), planks.end());

    int used = 0;

    for (int r = 0; r < rows; r++) {
        auto it = s.find(side);
        if (it != s.end()) {
            s.erase(it);
            used++;
            continue;
        }

        bool found = false;
        auto left = s.begin();
        auto right = prev(s.end());
        while (left != right) {
            int sum = *left + *right;
            if (sum == side) {
                auto l = left, rgt = right;
                ++left; --right;
                s.erase(l);
                s.erase(rgt);
                used += 2;
                found = true;
                break;
            } else if (sum < side) {
                ++left;
            } else {
                --right;
            }
        }

        if (!found) return -1; 
    }

    return used;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        int L, K;
        cin >> L >> K;
        vector<int> planks(K);
        for (int i = 0; i < K; i++) cin >> planks[i];

        int ans1 = ballroom(N, M, L, planks);
        int ans2 = ballroom(M, N, L, planks);

        if (ans1 == -1 && ans2 == -1) cout << "impossivel" << endl;
        else if (ans1 == -1) cout << ans2 << endl;
        else if (ans2 == -1) cout << ans1 << endl;
        else cout << min(ans1, ans2) << endl;
    }
}
