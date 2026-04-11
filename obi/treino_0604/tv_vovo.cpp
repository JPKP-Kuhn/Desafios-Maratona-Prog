#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()

using ll = long long;
using vll = vector<ll>;

int main() { _
    ll m, n;
    ll caso{};
    while(cin >> m >> n && m && n){
        vector<vll> mat(m, vll(n));
        vector<vll> res(m, vll(n));
        for (vll &v : mat) for (ll &x : v) cin >> x;

        ll x, y;
        ll total_x{}, total_y{};
        while(cin >> x >> y && !(x==0 && y==0)){
            total_x+=x;
            total_y+=y;
        }
        ll dx = ((total_x%n) + n) % n;
        ll dy = ((-total_y%m) + m) %m;

        for (ll i{}; i<m; i++)
            for (ll j{}; j<n; j++)
                res[(i + dy)%m][(j + dx)%n] = mat[i][j];

        cout << "Teste " << ++caso << '\n';
        for (ll i{}; i<m; i++){
            for (ll j{}; j<n; j++){
                if (j == 0) cout << res[i][j];
                else cout << ' ' << res[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}

