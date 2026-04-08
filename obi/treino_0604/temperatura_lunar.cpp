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
const ll EPS = -1e9;     // Valor para comparar double

int main() { _
    ll n, m;
    ll caso{};
    while(cin >> n >> m && n && m){
        vll temp(n); for (ll &x : temp) cin >> x;
        ll menor=100000, maior=-100000;
        for (ll i{}; i<n && i<=n-m; i++){
            ll soma{};
            for (ll j{}; j<m && i+j<n; j++){
                soma += temp[i+j];
            }
            ll media = soma/m;
            maior = max(maior, media);
            menor = min(menor, media);
        }

        cout << "Teste " << ++caso << '\n';
        cout << menor << ' ' << maior << "\n\n";
    }

    return 0;
}

