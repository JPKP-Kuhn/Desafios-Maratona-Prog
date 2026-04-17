#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;


int main() { _
    ll n; cin >> n;
    ll trilha{n+10};
    ll menor_peso=100000;
    ll o=1;
    while(n--){
        ll m; cin >> m;
        ll pesod{};
        ll pesoe{};
        ll t; cin >> t; m--;
        while(m--){
            ll x; cin >> x;
            if (x > t){
                pesod+=(x-t);
            }else{
                pesoe+=(t-x);
            }
            t=x;
        }
        if (pesoe < menor_peso || pesod < menor_peso){
            menor_peso=min({menor_peso, pesoe, pesod});
            trilha=o;
        }
        o++;
    }
    cout << trilha << '\n';
    return 0;
}

