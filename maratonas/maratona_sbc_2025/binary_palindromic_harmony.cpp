#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define BUFF ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
const int INF = 1e18+5;

signed main()
{
    BUFF;
    int n; cin >> n;

    map<int,int> pow2;
    for(int i = 1; i < 63; i++) {
        pow2[1<<i]++;
    }

    if(n == 1) cout << 1 << endl;
    else if(pow2[n]) cout << n-1 << endl;
    else {
        int bin = ceil(log2(n));

        vi binary(bin, 0); 
        int restante = n;

        int mid = (bin/2)-1;
        for(int i = 0; i <= mid; i++) {
            if(restante >= ((1ll<<i)+(1ll<<(bin-i-1)))) {
                binary[i] = binary[bin-i-1] = 1;
                restante -= ((1ll<<i)+(1ll<<(bin-i-1)));
            }
        }

        if(bin %2 == 1 && restante >= (1 << mid+1))  {
            binary[mid+1] = 1;
        }

        int res = 0;

        for(int i = 0; i < bin; i++) {
            res = 2*res+binary[i];
        }

        cout << res << endl;
    }
    return 0; 
}
