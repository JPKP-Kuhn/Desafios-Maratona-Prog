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
const double EPS = 1e-9;     // Valor para comparar double


int main() { _
    ll n; cin >> n;
    ll total{};
    vll escadas(n); for(ll &x : escadas){
        cin >> x;
        total+=x;
    }
    // total = n/2 * (x + x+n-1);
    double v = (total - n*(n-1.0)/2.0)/(double)n;
    if (v < 0 || fabs(v-(ll)v)>EPS){
        cout << -1 << '\n';
        return 0;
    }
    ll valor = v;
    ll mov{};
    for (ll i{}; i<n; i++){
        ll alvo=valor+i;
        if (escadas[i] > alvo)
            mov+=escadas[i]-alvo;

    }
    cout << mov << '\n';

    return 0;
}

