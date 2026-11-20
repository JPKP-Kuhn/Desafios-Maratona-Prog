#include <bits/stdc++.h>
using namespace std;
#define _                                                                                          \
    ios_base::sync_with_stdio(false);                                                              \
    cin.tie(NULL);                                                                                 \
    cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

const double PI = 3.14159265358979323846;
const ll MAXN = 1e5 + 10; // Range seguro para vetores e arrays
const ll INF = 1e18 + 5;  // PD e inicialização de valor mínimo
const ll MOD = 1e9 + 7;   // aritmética modular, números muito grandes
const double EPS = 1e-9;  // Valor para comparar double

struct point {
    ll x, y;
};

ll n;
bool vis[MAXN];
ll alcance;
ll cont{};
point torres[MAXN];
void dfs(ll i) {
    vis[i] = true;
    cont++;

    for (ll j = 0; j < n; j++) {
        ll dx = torres[i].x - torres[j].x;
        ll dy = torres[i].y - torres[j].y;
        if (!vis[j] && (dx * dx + dy * dy) <= alcance)
            dfs(j);
    }
}

int main() {
    _ cin >> n;
    for (ll i{}; i < n; i++) {
        point p;
        cin >> p.x >> p.y;
        torres[i] = p;
    }
    cin >> alcance;
    alcance = alcance * alcance;

    dfs(0);

    cout << (cont == n ? 'S' : 'N') << '\n';

    return 0;
}
