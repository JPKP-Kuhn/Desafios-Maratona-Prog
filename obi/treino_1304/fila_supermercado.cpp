#include <bits/stdc++.h>
#include <queue>
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
    ll n, m; cin >> n >> m;
    vll func(n); for (ll &x : func) cin >> x;
    vll cli(m); for (ll &x : cli) cin >> x;
    ll total{};

    priority_queue<pl, vpll, greater<pl>> tid;
    for (ll i{}; i<n; i++) tid.push({0, i});

    for (ll i{}; i<m; i++){
        auto [t, f] = tid.top();
        tid.pop();

        ll tempo = t + func[f] * cli[i];
        total = max(total, tempo);
        tid.push({tempo, f});
    }

    cout << total << '\n';

    return 0;
}

