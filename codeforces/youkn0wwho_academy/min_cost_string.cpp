#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll calc_custo(unordered_map<char, ll>&custo, string s){
    ll c{};
    for (ll i{}; i<(ll)s.size()-1; i++){
        char l1 = s[i], ln = s[i+1];
        ll p = abs(custo[l1] - custo[ln]);
        c += p;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    unordered_map<char, ll>custo;
    for (char i='a'; i<='z'; i++){
        ll x; cin >> x;
        custo[i]=x;
    }

    ll d = count(s.begin(), s.end(), '?');
    if (d == 0){}
    else if (d == (ll)s.size()){ // String composta apenas por '?'
        for (char &x : s) x = 'a';
    } else {
        // Começa com ?
        if (s[0] == '?'){
            ll ipos{}, jpos{};
            while(s[jpos]=='?')jpos++;
            // Encontrar a menor letra com o mesmo valor
            for (char l='a'; l<='z'; l++){
                if (custo[l] == custo[s[jpos]]){
                    for (ll i=ipos; i<jpos; i++) s[i]=l;
                    break;
                }
            }
        }
        // Termina com ?
        if (s[(ll)s.size()-1] == '?'){
            ll jpos = s.size()-1;
            while(s[jpos] == '?')jpos--;
            ll ipos = jpos+1;
            for(char l='a'; l<='z'; l++){
                if (custo[l] == custo[s[jpos]]){
                    for (ll i=ipos; i<(ll)s.size(); i++) s[i]=l;
                    break;
                }
            }
        }
        // ? entre duas letras
        for (ll i{}; i<(ll)s.size(); i++){
            if (s[i]=='?'){
                ll ipos=i, jpos=i;
                while(s[jpos]=='?') jpos++;
                ll l1=custo[s[ipos-1]], ln = custo[s[jpos]];
                ll v1 = min(l1, ln), v2 = max(l1, ln);
                char best = 0;

                for (char l='a'; l<='z'; l++){
                    if (custo[l] >= v1 && custo[l] <= v2){
                        best = l;
                        break;
                    }
                }
                if (best == 0){
                    ll menor = LLONG_MAX;
                    for (char l='a'; l<='z'; l++){
                        ll val = abs(custo[s[ipos-1]] - custo[l]) +
                                 abs(custo[l] - custo[s[jpos]]);
                        if (val < menor){
                            menor = val;
                            best = l;
                        }
                    }
                }
                for (ll k=ipos; k<jpos; k++) s[k] = best;
            }
        }
    }

    cout << calc_custo(custo, s) << '\n';
    cout << s << '\n';

    return 0;
}

