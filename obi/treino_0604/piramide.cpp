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
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

ll mat[101][101];
ll memo[101][101];
ll psoma[101][101];

ll solve(ll i, ll j){
    if (memo[i][j] != -1) return memo[i][j];
    if (i == 0) return mat[i][j];

    ll soma = psoma[i][j+i] - (j > 0 ? psoma[i][j-1] : 0);

    ll left = solve(i-1, j+1);
    ll right = solve(i-1, j);

    memo[i][j] = soma + min(left, right);
    return memo[i][j];
}

int main() { _
    ll n; cin >> n;
    memset(memo, -1, sizeof(memo));
    for (ll i{}; i<n; i++){
        for (ll j{}; j<n; j++){
            cin >> mat[i][j];
            psoma[i][j] = mat[i][j];
            if (j > 0) psoma[i][j] += psoma[i][j-1];
        }
    }
    cout << solve(n-1, 0) << '\n';
    return 0;
}

