#include <bits/stdc++.h>
#include <queue>
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
    ll linha, coluna; cin >> linha >> coluna; linha--; coluna--;
    vector<vll> mat(n, vll(n));
    vector<vb> bandeira(n, vb(n));
    for (ll i{}; i<n; i++){
        for (ll j{}; j<n; j++)
            cin >> mat[i][j];
    }
    queue<pl> fila;
    fila.push({linha, coluna});
    bandeira[linha][coluna]=true;
    ll c{1};

    vll dx = {0, 1, 0, -1};
    vll dy = {1, 0, -1, 0};
    while(!fila.empty()){
        ll li = fila.front().first;
        ll col = fila.front().second;
        fila.pop();

        for (ll k{}; k<4; k++){
            ll nx = li + dx[k];
            ll ny = col + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n){
                if (mat[nx][ny] >= mat[li][col] && !bandeira[nx][ny]){
                    c++;
                    bandeira[nx][ny] = true;
                    fila.push({nx, ny});
                }
            }
        }
    }
    cout << c << '\n';

    return 0;
}

