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

struct point {
    double x, y;
    point() {x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    };
};

int main() { _
    ll n; cin >> n;
    vector<string> nomes;
    ll comp{}, mal{};
    cin.ignore();
    while(n--){
        string a; getline(cin, a);
        if (a[0] == '+') comp++;
        else mal++;
        string nome = a.substr(2, a.size()-2);
        nomes.pb(nome);
    }
    sort(all(nomes));
    for (string nome : nomes) cout << nome << '\n';
    cout << "Se comportaram: " << comp << " | Nao se comportaram: " << mal << '\n';

    return 0;
}

