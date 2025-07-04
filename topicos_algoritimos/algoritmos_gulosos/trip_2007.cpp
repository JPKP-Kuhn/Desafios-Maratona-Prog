#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n{};
    bool first = true;
    while (cin >> n && n != 0){
        
        if (!first) cout << '\n';
        
        first = false;
        vector<ll> bags(n);
        for (ll i=0; i<n; i++){
            cin >> bags[i];
        }
        sort(bags.begin(), bags.end());
        map<ll, ll> contagem;
        
        for (ll i : bags){
            contagem[i]++;
        }
        
        ll totBagUsadas{};
        
        for (const auto &par : contagem){
            if (par.second > totBagUsadas){
                totBagUsadas = par.second;
            }
        }
        
        vector<vector<ll>> bigBag(totBagUsadas);
        for (ll i=0; i<n; i++){
            bigBag[i % totBagUsadas].push_back(bags[i]);
        }
        
        cout << totBagUsadas <<'\n';
        for (const auto &moc : bigBag){
            for (ll i=0; i<moc.size(); i++){
                cout << moc[i];
                if (i % moc.size()-1){
                    cout << ' ';
                } else {
                    cout << '\n';
                }
            }
        }
    }
    return 0;
}
