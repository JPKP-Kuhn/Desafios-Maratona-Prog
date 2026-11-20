#include <bits/stdc++.h>
using namespace std;
#define _                                                                                          \
    ios_base::sync_with_stdio(false);                                                              \
    cin.tie(NULL);                                                                                 \
    cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

int main() {
    _ ll n, m;
    cin >> n >> m;
    queue<pl> q;
    pl fim, inicio;
    vector<vb> mat(n, vb(m, false));
    vector<vpll> pai(n, vpll(m));
    vector<vector<char>> mov(n, vector<char>(m));
    for (ll i{}; i < n; i++) {
        string s;
        cin >> s;
        for (ll j{}; j < m; j++) {
            if (s[j] == 'A') {
                q.push({i, j});
                inicio.fr = i;
                inicio.sc = j;
                pai[i][j] = {-1, -1};
            } else if (s[j] == 'B') {
                fim.fr = i;
                fim.sc = j;
                mat[i][j] = true;
            } else if (s[j] == '.') {
                mat[i][j] = true;
            }
        }
    }

    vll dx = {0, 1, 0, -1};
    vll dy = {1, 0, -1, 0};

    string ans{};
    bool f = false;
    while (!q.empty()) {
        pl p = q.front();
        ll i = p.fr, j = p.sc;
        q.pop();
        if (p == fim) {
            f = true;
            pl volta = fim;
            while (volta != inicio) {
                ans += mov[volta.fr][volta.sc];
                volta = pai[volta.fr][volta.sc];
            }
            break;
        }

        for (ll d{}; d < 4; d++) {
            ll nx = i + dx[d];
            ll ny = j + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny]) {
                q.push({nx, ny});
                mat[nx][ny] = false;
                pai[nx][ny] = {i, j};

                if (d == 0) {
                    mov[nx][ny] = 'R';
                } else if (d == 1) {
                    mov[nx][ny] = 'D';
                } else if (d == 2) {
                    mov[nx][ny] = 'L';
                } else if (d == 3) {
                    mov[nx][ny] = 'U';
                }
            }
        }
    }

    if (!f) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << ans.size() << '\n';
        reverse(all(ans));
        cout << ans << '\n';
    }

    return 0;
}
