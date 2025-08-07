#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<tuple<int, int, int>> pistas(k);
    for (int i = 0; i < k; ++i) {
        int x, y, d;
        cin >> x >> y >> d;
        pistas[i] = {x, y, d};
    }

    int count = 0;
    int ansX = -1, ansY = -1;

    // Testa todas as posições possíveis do grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool ok = true;
            for (auto &[px, py, dist] : pistas) {
                int d = abs(i - px) + abs(j - py);
                if (d != dist) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                count++;
                ansX = i;
                ansY = j;
            }
        }
    }

    if (count == 1) {
        cout << ansX << " " << ansY << "\n";
    } else {
        cout << "-1 -1\n";
    }

    return 0;
}

