#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

int main() { _
    double a, g, ra, rg; cin >> a >> g >> ra >> rg;
    double pa = ra/a;
    double pg = rg/g;
    if (pa > pg) cout << "A\n";
    else cout << "G\n";

    return 0;
}

