#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

ll procura_menor(stack<ll> pilha){
    ll menor=1e10;
    while(!pilha.empty()){
        menor = min(menor, pilha.top());
        pilha.pop();
    }
    return menor;
}

int main() { _
    ll n; cin >> n;
    stack<ll> saco;
    while(n--){
        string m;
        cin >> m;
        if (m == "PUSH"){
            ll num; cin >> num;
            saco.push(num);
        } else if (m == "MIN") {
            if (saco.empty()) cout << "EMPTY\n";
            else {
                cout << procura_menor(saco) << '\n';
            }
        } else if (m == "POP"){
            if (saco.empty()) cout << "EMPTY\n";
            else saco.pop();
        }
    }

    return 0;
}

