#include <bits/stdc++.h>
#include <unordered_map>
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

pair<bool, ll> outro(ll carta, ll vez, vpll &jogadores){
    for (ll i{}; i<(ll)jogadores.size(); i++){
        if (i == vez) continue;
        if (jogadores[i].sc == carta) return {true, i};
    }
    return {false, -1};
}

int main() { _
    ll n, j;
    while(cin >> n >> j && n && j){
        vpll jogadores(j);
        unordered_map<ll, ll>descarte;
        ll vez{};
        ll qtd_cartas{};
        for(ll idx{}; idx<n; idx++){
            ll carta_vez; cin >> carta_vez;

            if (descarte[carta_vez]>0){
                jogadores[vez].fr+=2;
                jogadores[vez].sc=carta_vez;
                descarte[carta_vez]--;
                qtd_cartas = max(qtd_cartas, jogadores[vez].fr);
                continue;
            }
            pair<bool, ll> ou = outro(carta_vez, vez, jogadores);
            if (ou.fr){
                jogadores[vez].fr += jogadores[ou.sc].fr + 1;
                jogadores[vez].sc = carta_vez;
                jogadores[ou.sc].fr = 0; jogadores[ou.sc].sc = 0;
                qtd_cartas = max(qtd_cartas, jogadores[vez].fr);
                continue;
            }
            if (carta_vez == jogadores[vez].sc){
                jogadores[vez].fr++;
                jogadores[vez].sc=carta_vez;
                qtd_cartas = max(qtd_cartas, jogadores[vez].fr);
                continue;
            }
            descarte[carta_vez]++;
            vez = (vez + 1) % j;
        }
        cout << qtd_cartas;
        for (ll i{}; i<j; i++){
            if (jogadores[i].fr == qtd_cartas)
                cout << ' ' << i+1;
        }
        cout << '\n';
    }

    return 0;
}

