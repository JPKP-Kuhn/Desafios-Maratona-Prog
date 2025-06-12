#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll maxDist = 0;
    
    // Para cada prédio i, encontramos o melhor prédio j à sua direita
    // e o melhor prédio j à sua esquerda
    
    // Vetor para armazenar o máximo (a[j] + j) para j >= i
    vector<ll> maxRight(n);
    maxRight[n-1] = a[n-1] + (n-1);
    
    for (ll i = n-2; i >= 0; i--) {
        maxRight[i] = max(maxRight[i+1], a[i] + i);
    }
    
    // Vetor para armazenar o máximo (a[j] - j) para j <= i
    vector<ll> maxLeft(n);
    maxLeft[0] = a[0] - 0;
    
    for (ll i = 1; i < n; i++) {
        maxLeft[i] = max(maxLeft[i-1], a[i] - i);
    }
    
    // Para cada prédio i, calculamos a máxima distância possível
    for (ll i = 0; i < n; i++) {
        // Caso 1: prédio i com algum prédio à sua direita
        if (i < n-1) {
            ll dist1 = a[i] - i + maxRight[i+1];
            maxDist = max(maxDist, dist1);
        }
        
        // Caso 2: prédio i com algum prédio à sua esquerda
        if (i > 0) {
            ll dist2 = a[i] + i + maxLeft[i-1];
            maxDist = max(maxDist, dist2);
        }
    }
    
    cout << maxDist << '\n';
    
    return 0;
}
