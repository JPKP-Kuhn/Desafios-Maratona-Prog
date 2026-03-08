#include <bits/stdc++.h>
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll p, s; cin >> p >> s;
    vpll intervalo;
    vpll val(s);
    for (ll i{}; i<s; i++){
        cin >> val[i].first >> val[i].second;
    }
    sort(val.begin(), val.end());
    intervalo.push_back({val[0].first, val[0].second});
    ll i=1;
    bool pri=true;
    for (auto &[f, s] : val){
        if (pri){
            pri = false; continue;
        }
        if (f <= intervalo[i-1].second && s > intervalo[i-1].second){
            intervalo[i-1].second = s;
        } else if (f > intervalo[i-1].second){
            intervalo.push_back({f, s});
            i++;
        }
    }
    for (auto &[f, s] : intervalo){
        cout << f << ' ' << s << '\n';
    }

    return 0;
}

