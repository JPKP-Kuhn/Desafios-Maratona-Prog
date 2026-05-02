#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define LSOne(S) ((S) & -(S)) // bit menos significativo ligado, bitmask

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

int main() { _
    string s;
    while(cin >> s && s!="-1"){
        if (s.length() > 2 && s[1]=='x'){
            unsigned int n = stoi(s, nullptr, 16);
            printf("%d\n", n);
        } else {
            unsigned int n = stoi(s);
            printf("0x%X\n", n);
        }
    }

    return 0;
}

