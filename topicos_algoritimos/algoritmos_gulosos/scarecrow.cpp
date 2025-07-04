#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t{};
    cin >> t;
    for (ll test = 1; test <= t; test++){
        ll n;
        cin >> n;
        
        string field;
        cin >> field;
        // . fértil, e # infértil
        vector<bool> usado(field.length(), false);
        ll scarescrow{};
        for (ll i=0; i<field.length(); i++){
            if (field[i] == '.' && !usado[i]){
                scarescrow++;
                usado[i] = true;
                usado[i+1] = true;
                usado[i+2] = true;
            }
        }
        cout << "Case " << test << ": " << scarescrow << '\n';
    }
    return 0;
}
