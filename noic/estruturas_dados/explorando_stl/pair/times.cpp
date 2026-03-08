#include <bits/stdc++.h>
#include <utility>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t; cin >> n >> t;
    ll o{};
    vector<vector<pair<string, ll>>> equi(t);
    vector<pair<ll, string>> hab;
    for (ll i{}; i<n; i++){
        string nome; ll h; cin >> nome >> h;
        hab.push_back(make_pair(h, nome));
    }
    sort(hab.rbegin(), hab.rend());
    for (ll i{}; i<n; i++){
        string nome = hab[i].second;
        ll h = hab[i].first;
        pair<string, ll> p = make_pair(nome, h);
        equi[o].push_back(p);
        o++; o %= t;
    }

    for (ll i{}; i<t; i++){
        cout << "Time " << i+1 << '\n';
        sort(equi[i].begin(), equi[i].end());
        for (auto &[f, s] : equi[i]){
            cout << f << '\n';
        }
        cout << '\n';
    }

    return 0;
}

