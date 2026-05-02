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


// M_PI para número PI
const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo
const ll MOD = 1e9+7;    // Valor comum para aritmética modular, números muito grandes
const double EPS = 1e-9; // Valor para comparar double


int main() { _
    ll l, c, m, n; cin >> l >> c >> m >> n;
    vector<vll> mat(l, vll(c));
    vector<vll> psum(l+1, vll(c+1, 0));
    for (ll i{}; i<l; i++){
        for (ll j{}; j<c; j++){
            cin >> mat[i][j];
            psum[i+1][j+1] = mat[i][j] + psum[i][j+1] + psum[i+1][j] - psum[i][j];
        }
    }

    ll maior=0;
    for (ll i{1}; i+m<=l+1; i++){
        for (ll j{1}; j+n<=c+1; j++){
            maior = max(maior, psum[i+m-1][j+n-1] - psum[i-1][j+n-1] - psum[i+m-1][j-1] + psum[i-1][j-1]);
        }
    }
    cout << maior << '\n';

    return 0;
}

