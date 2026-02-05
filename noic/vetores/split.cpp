#include <bits/stdc++.h>
using namespace std;

int main(){
    // Seu código vai aqui
    int n, m{}; cin >> n;
    vector<int> v(n);
    for (int &x : v){
      cin >> x;
      m=max(m, x);
    }
    int soma{};
    for (int i : v){
      if (i < m){
        soma+=i;
      } else if (i == m){
        cout << soma << '\n';
        soma=0;
      }
    }
    cout << soma << '\n';

    return 0;
}
