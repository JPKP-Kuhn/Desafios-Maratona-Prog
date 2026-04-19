#include <bits/stdc++.h>
#include <sstream>
#include <stack>
#include <string>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;


int main() { _
    ll n;
    while(cin >> n && n){
        string line;
        cin.ignore();
        while(getline(cin, line) && line[0]!='0'){
            stringstream ss(line);
            ll num;
            ll p=1;
            stack<ll>estacao;
            while(ss >> num){
                while(p <= n && (estacao.empty() || estacao.top() != num)){
                    estacao.push(p++);
                }

                if (!estacao.empty() && estacao.top() == num) estacao.pop();
            }
            if (estacao.empty()) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << '\n';
    }
    return 0;
}

