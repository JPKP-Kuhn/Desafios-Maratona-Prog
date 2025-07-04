#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    vector<pair<ll, ll>> tasks(n);
    for (ll i = 0; i<n; i++){
        ll t, d;
        cin >> t >> d;
        tasks[i].first = t;
        tasks[i].second = d;
    }
    sort(tasks.begin(), tasks.end());
    ll maxReward{}, total_time{};
    for (ll i = 0; i<n; i++){
        total_time+=tasks[i].first;
        maxReward += (tasks[i].second - total_time);
    }
  
    cout << maxReward << '\n';
    return 0;
}
