#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    ll c{};

    // Crivo de Eratóstenes
    vb is_prime(n+1, true);
    vll primos;
    is_prime[0] = is_prime[1] = false;
    for (ll i=2; i<=n; i++){
        if (is_prime[i]){
            primos.push_back(i);
            for (ll j=i; j<=n; j+=i){
                if (j == i) continue;
                is_prime[j]=false;
            }
        }
    }

    for (ll num : primos){
        cout << num << ' ';
    }
    cout << '\n';

    for (ll i=1; i<=n; i++){
        ll p{};
        for (ll num : primos){
            if (i%num==0) p++;
        }
        if (p==2) c++;
    }
    cout << c << '\n';
    return 0;
}

