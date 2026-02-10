#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> mat{};
    int m=-1e9;
    for (int i{}; i<3; i++){
        vector<int> r{};
        for (int j{}; j<3; j++){
            int x; cin >> x;
            m=max(m, x);
            r.push_back(x);
        }
        mat.push_back(r);
    }

    for(vector<int> r : mat){
        for (int i : r){
            if (i==m) cout << -1 << ' ';
            else cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}

