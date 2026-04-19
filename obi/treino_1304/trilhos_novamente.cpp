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


int main() { _
    ll n;
    while(cin >> n && n){
        vector<char> e(n); for (char &x : e) cin >> x;
        vector<char> obj(n); for (char &x : obj) cin >> x;
        stack<char>passos;
        ll idx{};
        for (ll c{}; c<n; c++){
            char s = obj[c];

            while((passos.empty() || passos.top() != s) && idx < n){
                passos.push(e[idx++]); cout << 'I';
            }

            if (!passos.empty() && passos.top() == s){
                passos.pop(); cout << 'R';
            } else {
                cout << " Impossible";
                goto fim;
            }
        }
    fim:
        cout << '\n';
    }

    return 0;
}

