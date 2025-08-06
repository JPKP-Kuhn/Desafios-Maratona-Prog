#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


bool comp(tuple<string, ll , ll, ll>a, tuple<string, ll, ll, ll>b){
  if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
  if (get<2>(a) != get<2>(b)) return get<2>(a) > get<2>(b);
  if (get<3>(a) != get<3>(b)) return get<3>(a) < get<3>(b);

  return get<0>(a) < get<0>(b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin >> n;

  vector<tuple<string, ll, ll, ll>> na_pod_kil_mor(n);

  for (ll i=0; i<n; i++){
    string name; cin >> name;
    ll p, k, m; cin >> p >> k >> m;

    get<0>(na_pod_kil_mor[i]) = name;
    get<1>(na_pod_kil_mor[i]) = p;
    get<2>(na_pod_kil_mor[i]) = k;
    get<3>(na_pod_kil_mor[i]) = m;
  }

  sort(na_pod_kil_mor.begin(), na_pod_kil_mor.end(), comp);


  cout << get<0>(na_pod_kil_mor[0]) << '\n';

  return 0;
}

