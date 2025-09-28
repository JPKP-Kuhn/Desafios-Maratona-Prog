#include <bits/stdc++.h>
#include <cstdlib>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t{};
  cin >> t;
  while(t--){
    ll n{};
    cin >> n;
    vll notes(n);
    for (ll i=0;i<n;i++){
      cin >> notes[i];
    }
    bool teste = true;
    for (ll i=0;i<n-1;i++){
      ll semitone = abs(notes[i] - notes[i+1]);
      if (semitone != 5 && semitone != 7) {
        teste = false;
        break;
      }
    }
    cout << (teste ? "YES\n" : "NO\n");
  }

  return 0;
}

