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


ll c{};
void hanoi(ll n){
    c++;
    if (n == 0 || n == 1) return;
    hanoi(n-1);
    hanoi(n-1);
}
int main() { _
    ll n;
    ll caso{};
    while(cin >> n && n){
        c = 0;
        cout << "Teste " << ++caso << '\n';
        hanoi(n);
        cout << c << "\n\n";
    }
    return 0;
}

