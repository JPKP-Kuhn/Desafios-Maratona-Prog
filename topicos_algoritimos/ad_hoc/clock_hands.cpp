#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;
using pl = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, m;
    while(scanf("%d:%d", &h, &m) && !(h==0 && m==0)){
        double angH = 30;
        double angM = 6;
        double angHM = 0.5;

        double ah = (h==12 ? 0 : h*angH);
        double am = m*angM;

        double angle{};
        if (ah > am){
            double d = (ah + angHM*m - am);
            if (d > 180) angle = 360 - d;
            else angle = d;

        } else {
            double d = am - (ah + angHM*m);
            if (d > 180) angle = 360 - d;
            else angle = d;
        }
        angle = (angle == 360.0 ? 0 : angle);

        printf("%.3f\n", angle);
    }

    return 0;
}

