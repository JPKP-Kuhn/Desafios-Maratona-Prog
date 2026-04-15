#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;


int main() { _
    ll n, m; cin >> n >> m;
    vector<vll> mat(n, vll(m)); for (vll &v : mat) for (ll &x : v) cin >> x;

    ll maior{};
    for (ll i{}; i<n; i++){
        ll somalinha{};
        for (ll j{}; j<m; j++){
            somalinha+=mat[i][j];
        }
        maior = max(maior, somalinha);
    }
    for (ll j{}; j<m; j++){
        ll somacoluna{};
        for (ll i{}; i<n; i++){
            somacoluna+=mat[i][j];
        }
        maior = max(maior, somacoluna);
    }

    cout << maior << '\n';
    return 0;
}

