#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

vector<vector<ull>> dp;

ull count_calls(int n, int back) {
    if (n <= 0) return 1; // conta como chamada
    if (n == 1) return 1; // conta como chamada

    ull &res = dp[n][back];
    if (res != ULLONG_MAX) return res;

    res = 1; // conta esta chamada
    for (int i = 1; i <= back; i++) {
        res += count_calls(n - i, back);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, back;
    int case_num = 1;

    while (cin >> n >> back && n <= 60) {
        dp.assign(n + 1, vector<ull>(back + 1, ULLONG_MAX));
        ull total_calls = count_calls(n, back);
        cout << "Case " << case_num++ << ": " << total_calls << '\n';
    }

    return 0;
}

