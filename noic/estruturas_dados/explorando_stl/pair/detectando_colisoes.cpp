#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;


struct ret{
    ll x0, x1, y0, y1;
    bool operator<(const ret& other) const {
        if (x0 != other.x0) return x0 < other.x0;
        if (x1 != other.x1) return x1 < other.x1;
        if (y0 != other.y0) return y0 < other.y0;
        return y1 < other.y1;
    }
};

bool col(ret r1, ret r2){
    if (r1.x1 < r2.x0) return false;
    if (r2.x1 < r1.x0) return false;
    if (r1.y1 < r2.y0) return false;
    if (r2.y1 < r1.y0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ret r1, r2;
    cin >> r1.x0 >> r1.y0 >> r1.x1 >> r1.y1;
    cin >> r2.x0 >> r2.y0 >> r2.x1 >> r2.y1;
    vector<ret> v = {r1, r2};
    sort(v.begin(), v.end());
    if (col(v[0], v[1])) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}

