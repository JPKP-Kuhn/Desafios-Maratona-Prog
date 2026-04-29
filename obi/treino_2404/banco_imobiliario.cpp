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
    ll qtd_i, n; cin >> qtd_i >> n;
    map<char, ll> pessoa = {{'D', qtd_i}, {'E', qtd_i}, {'F', qtd_i}};
    while(n--){
        char op; cin >> op;
        char pe; cin >> pe;

        if (op == 'C'){
            ll valor; cin >> valor;
            pessoa[pe]-=valor;
        } else if (op == 'V') {
            ll valor; cin >> valor;
            pessoa[pe]+=valor;
        } else if (op == 'A'){
            char paga; cin >> paga;
            ll valor; cin >> valor;
            pessoa[pe]+=valor;
            pessoa[paga]-=valor;
        }
    }
    cout << pessoa['D'] << ' ' <<  pessoa['E'] << ' ' <<  pessoa['F'];
    cout << '\n';

    return 0;
}

