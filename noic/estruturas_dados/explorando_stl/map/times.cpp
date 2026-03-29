#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t; cin >> n >> t;
    vector<vector<string>> time(t);
    map<ll, string, greater<ll>> habilis;
    while(n--){
        string aluno; ll hab; cin >> aluno >> hab;
        habilis[hab]=aluno;
    }
    ll o{};
    for (auto &[f, s] : habilis){
        time[o].push_back(s);
        o = (o+1)%t;
    }

    for (ll i{}; i<t; i++){
        cout << "Time " << i+1 << '\n';
        sort(time[i].begin(), time[i].end());
        for (string s : time[i]){
            cout << s << '\n';
        }
        cout << '\n';
    }

    return 0;
}

