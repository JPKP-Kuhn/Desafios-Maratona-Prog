#include <bits/stdc++.h>
#include <unordered_map>
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
    unordered_map<ll, ll>freq;
    vll num;
    unordered_set<ll> s;
    ll x;
    while(cin >> x){
        if (s.find(x) == s.end()){
            s.insert(x);
            num.push_back(x);
        }
        freq[x]++;
    }
    for (ll i : num){
        cout << i << ' ' << freq[i] << '\n';
    }

    return 0;
}

