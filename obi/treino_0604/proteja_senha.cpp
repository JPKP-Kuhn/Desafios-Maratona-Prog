#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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


int main() { _
    ll n;
    ll caso{};
    while(cin >> n && n){
        string senha;
        vector<set<ll>> poss(6);
        for (ll i{}; i<6; i++){
            for (ll d{}; d<=9; d++) poss[i].insert(d);
        }
        while (n--){
            unordered_map<char, pl> cs;
            char l = 'A';
            for (ll i{}; i<5; i++){
                ll f, s; cin >> f >> s;
                cs[l++] = {f, s};
            }
            for (ll i{}; i<6; i++){
                char le; cin >> le;

                set<ll> atual;
                atual.insert(cs[le].first);
                atual.insert(cs[le].second);

                set<ll> inter;
                set_intersection(all(poss[i]), all(atual), inserter(inter, inter.begin()));
                // for (ll x : poss[i]){
                //     if (atual.count(x)) inter.insert(x);
                // }
                poss[i] = inter;
            }
        }
        cout << "Teste " << ++caso << '\n';
        for (ll i{}; i<6; i++){
            cout << *poss[i].begin() << ' ';
        }

        cout << "\n\n";
    }

    return 0;
}

