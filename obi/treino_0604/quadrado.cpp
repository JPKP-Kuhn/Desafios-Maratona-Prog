#include <bits/stdc++.h>
#include <unordered_map>
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


int main() { _
    ll n; cin >> n;
    vector<vll>mat(n, vll(n));
    for (ll i{}; i<n; i++){
        for (ll j{}; j<n; j++){
            cin >> mat[i][j];
        }
    }
    vll somasl{}, somasc{};
    unordered_map<ll, ll> cl, cc;
    for (ll i{}; i<n; i++){
        ll somal{}, somac{};
        for (ll j{}; j<n; j++){
            somal+=mat[i][j];
            somac+=mat[j][i];
        }
        cl[somal]++; cc[somac]++;
        somasl.push_back(somal);
        somasc.push_back(somac);
    }
    ll lierr, colerr, licor, colcor;
    for (ll i{}; i<n; i++){
        if (cl[somasl[i]]==1){
            lierr=i; break;
        } else licor=somasl[i];
    }

    for (ll j{}; j<n; j++){
        if (cc[somasc[j]]==1){
            colerr=j; break;
        } else colcor=somasc[j];
    }
    ll soma{};
    for (ll j{}; j<n; j++){
        if (j!=colerr)soma+=mat[lierr][j];
    }
    ll errado = mat[lierr][colerr];
    cout << licor-soma << ' ' << errado << '\n';

    return 0;
}

