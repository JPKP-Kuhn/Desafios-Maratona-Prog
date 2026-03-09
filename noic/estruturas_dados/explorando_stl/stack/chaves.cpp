#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    cin.ignore();
    string s{};
    while(t--){
        string line; getline(cin, line);
        s+=line;
    }
    stack<char> p;
    bool ok=true;
    for (char c : s){
        if (c == '{') p.push(c);
        else if (c == '}'){
            if (p.empty()){
                ok = false;
                break;
            } else {
                p.pop();
            }
        }
    }
    if (ok && p.empty()) cout << "S\n";
    else cout << "N\n";

    return 0;
}

