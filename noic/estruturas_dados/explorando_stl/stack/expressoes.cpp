#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<char> p;
        bool ok=true;
        for (char c : s){
            if (c == '(' || c == '[' || c == '{') p.push(c);
            else {
                if (p.empty()){
                    ok = false;
                    break;
                } else {
                    char l = p.top();
                    p.pop();
                    if ((l == '(' && c != ')') || (l == '[' && c != ']') || (l == '{' && c != '}')){
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok && p.empty()) cout << "S\n";
        else cout << "N\n";
    }

    return 0;
}

