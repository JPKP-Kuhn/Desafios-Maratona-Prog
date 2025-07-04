#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, d, r;
    
    while (cin >> n >> d >> r && (n != 0 && d != 0 && r != 0)){
        vector<ll> morning(n);
        for (ll i=0; i<n; i++){
            cin >> morning[i];
        }
        sort(morning.begin(), morning.end());
        
        vector<ll> afternoon(n);
        for (ll i=0; i<n; i++){
            cin >> afternoon[i];
        }
        sort(afternoon.rbegin(), afternoon.rend());
        ll overtime{};
        for (ll i=0; i<n; i++){
            ll totTime = morning[i] + afternoon[i];
            if (totTime > d){
                overtime += ((totTime - d));
            }
        }
        cout << overtime*r << '\n';
    }
    return 0;
}
