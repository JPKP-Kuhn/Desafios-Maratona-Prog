#include <bits/stdc++.h>
#include <bitset>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1000001;// Range seguro para vetores e arrays
const ll INF = 1e18+5;          // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  bitset<MAXN> minutes;
  while (cin >> n >> m && (n != 0 || m != 0)){
    bool conflito = false;
    for (ll i=0;i<n;i++){
      ll start, end;
      cin >> start >> end;


      if (!conflito) {
        for (ll j=start;j<end && j<MAXN;j++){
          if (minutes.test(j)){
            conflito = true;
            break;
          } 
          minutes.set(j);
        }
      }
    }
    for (ll i = 0; i < m; i++) {
      ll start, end, interval;
      cin >> start >> end >> interval;
      for (ll k = 0; start + k * interval < MAXN && !conflito; k++){
        ll task_start = start + k*interval;
        ll task_end = end + k*interval;

        if (task_start >= MAXN) break;
        if (task_end > MAXN) task_end = MAXN;

        if (!conflito){
          for (ll j=task_start;j<task_end;j++){
            if (minutes.test(j)){
              conflito = true;
              break;
            } 
            minutes.set(j);
          }
        }
      }
    }
    cout << ((!conflito) ? "NO CONFLICT\n" : "CONFLICT\n");
    conflito = false;
    minutes.reset();
  }

  return 0;
}

