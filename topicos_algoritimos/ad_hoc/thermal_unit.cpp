#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = double;
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

double to_c(double f){
    return (f- 32)/(9.0/5.0);
}

double to_f(double c){
    return 9.0/5.0 * c + 32;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    int c{};
    while(t--){
        ll celsius, increase_f; cin >> celsius >> increase_f;

        cout << "Case " << ++c << ": ";
        cout << fixed << setprecision(2) << to_c(to_f(celsius)+increase_f) << '\n';
    }

    return 0;
}

