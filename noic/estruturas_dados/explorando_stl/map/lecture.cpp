#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m; cin >> n >> m;
    unordered_map<string, string>dic;
    while(m--){
        string a, b; cin >> a >> b;
        dic[a]=b;
    }
    while(n--){
        string q; cin >> q;
        if (q.size() <= dic[q].size()) cout << q << ' ';
        else cout << dic[q] << ' ';
    }
    cout << '\n';

    return 0;
}

