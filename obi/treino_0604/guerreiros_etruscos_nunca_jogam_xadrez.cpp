#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = unsigned long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

/*linha   total
 *  1       1
 *  2       3
 *  3       6
 *  4       10
 *  5       15
 *  6       21
 *  n1 = 1
 *  total_linha_n = total_n-1 + n
 *  total_linha_n = (total_n-2 + n-1) + n
 *  total_linha_n = ((total_n-3 + n-2) + n-1) + n
 */

int main() { _
    ll n; cin >> n;
    while(n--){
        ll x; cin >> x;
        // soma naturais
        // st = ((1+x)*x)/2
        // st*2 = x + x²
        // x² + x - x*2 = 0
        ll delta = 1 - 4 * (-x*2);
        ll x1 = (-1 + sqrt(delta))/2;

        cout << x1 << '\n';
    }

    return 0;
}

