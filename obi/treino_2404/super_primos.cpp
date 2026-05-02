#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

bool primo(ll x){
    if (x < 2) return false;
    if (x%2==0) return x==2;

    for (ll i=3; i*i <= x; i+=2){
        if (x%i==0) return false;
    }
    return true;
}

bool super(ll x){
    ll d=0;
    while(x > 0){
        d = x%10;
        x/=10;
        if (!primo(d)) return false;
    }
    return true;
}

int main() { _
    ll n;
    while(cin >> n){
        if (!primo(n)){
            cout << "Nada\n";
        } else {
            if (super(n)) cout << "Super\n";
            else cout << "Primo\n";
        }
    }

    return 0;
}

