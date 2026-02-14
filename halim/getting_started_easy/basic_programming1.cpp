#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, t; cin >> n >> t;
  vll a(n);
  for (ll &x : a) cin >> x;

  if (t==1){
    cout << 7 << '\n';
  } else if (t==2){
    if (a[0] > a[1]) cout << "Bigger\n";
    else if (a[0] == a[1]) cout << "Equal\n";
    else cout << "Smaller\n";
  } else if (t==3){
    vll median = {a[0], a[1], a[2]};
    sort(median.begin(), median.end());
    cout << median[1] << '\n';
  } else if (t==4){
    cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
  } else if (t==5){
    cout << accumulate(a.begin(), a.end(), 0LL, [](ll acc, ll v){
        return (v%2==0) ? acc+v : acc;
        }) << '\n';
  } else if (t==6){
    for (ll &i : a){
      i %= 26;
      cout << (char)(i+'a');
    }
    cout << '\n';
  } else if (t==7){
    ll i{};
    set<ll> visited;
    while(1){
      if (i>n-1 || i < 0){
        cout << "Out\n";
        break;
      }

      if (i==n-1){
        cout << "Done\n";
        break;
      }

      if (visited.count(i)){
        cout << "Cyclic\n";
        break;
      }
      visited.insert(i);
      i = a[i];
    }
  }

  return 0;
}

