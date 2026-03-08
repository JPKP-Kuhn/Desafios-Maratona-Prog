#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll n;
vll v;

void merge(ll ini, ll mid, ll fim){
  ll n1 = mid - ini + 1;
  ll n2 = fim-mid;

  vll L(n1), R(n2);

  for (ll i{}; i<n1; i++) L[i] = v[ini+i];

  for (ll j{}; j<n2; j++) R[j] = v[mid+1+j];

  ll i{}, j{}, k=ini;

  while(i < n1 && j < n2){
    if (L[i] <= R[j]){
      v[k] = L[i];
      i++;
    } else {
      v[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < n1){
    v[k] = L[i];
    i++; k++;
  }

  while(j < n2){
    v[k] = R[j];
    j++; k++;
  }
}

void merge_sort(ll ini, ll fim) {
  if (ini >= fim) return;

  ll mid = ini + (fim-ini)/2;
  merge_sort(ini, mid);
  merge_sort(mid+1, fim);
  merge(ini, mid, fim);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  v.resize(n);
  for(ll &x : v) cin >> x;
  merge_sort(0, n-1);
  for (ll i : v) cout << i << ' ';
  cout << '\n';

  return 0;
}

