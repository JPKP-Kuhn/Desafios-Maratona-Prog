#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue<char> q;
    for (char l='A'; l<='P'; l++){
        q.push(l);
    }

    for (ll i{}; i<15; i++){
        ll m, n; cin >> m >> n;
        char f = q.front(); q.pop();
        char s = q.front(); q.pop();
        if (m > n) q.push(f);
        else q.push(s);
    }
    cout << q.front() << '\n';

    return 0;
}

