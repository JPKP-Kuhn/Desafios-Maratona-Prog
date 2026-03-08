#include <bits/stdc++.h>
using namespace std;

int main(){
   int n, m{}; cin >> n;
    map<int, int> oc;
    for (int i{}; i<n; i++){
        int x; cin >> x;
        oc[x]++;
        m=max(m, oc[x]);
    }
    set<int> num;
    for (auto &[k, v] : oc){
        if (v==m) num.insert(k);
    }
    for (int k : num){
        cout << k << ' ';
    }
    cout << '\n';

    return 0;
}

