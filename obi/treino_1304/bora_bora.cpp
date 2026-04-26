#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using ll = long long;

// C D H S
int ordemNaipe(char n){
    if (n == 'C') return 0;
    if (n == 'D') return 1;
    if (n == 'H') return 2;
    if (n == 'S') return 3;
    return 4;
}
struct carta{
    ll num;
    char naipe;

    bool operator<(carta other) const {
        if (num != other.num) return num < other.num;
        return ordemNaipe(naipe) < ordemNaipe(other.naipe);
    }
};

int main() { _
    ll p, m, n;
    while(cin >> p >> m >> n && p && m && n){
        stack<carta> descarte;
        queue<carta> saque;

        vector<deque<carta>> jogadores(p);
        for (ll i{}; i<p; i++){
            for (ll j{}; j<m; j++){
                carta c;
                cin >> c.num >> c.naipe;
                jogadores[i].push_back(c);
            }
            sort(jogadores[i].rbegin(), jogadores[i].rend());
        }
        bool direcao=true;
        auto proximo = [&](ll atual){
            if (direcao) return (atual+1)%p;
            return (atual-1 + p)%p;
        };
        auto pular = [&](ll atual){
            return proximo(proximo(atual));
        };
        ll vez{};

        carta pri; cin >> pri.num >> pri.naipe;
        descarte.push(pri);

        ll resto = n - (p*m+1);
        for (ll i{}; i<resto; i++){
            carta c; cin >> c.num >> c.naipe;
            saque.push(c);
        }

        if (pri.num == 12) {
            direcao=!direcao;
        } else if (pri.num == 7){
            jogadores[vez].push_back(saque.front()); saque.pop();
            jogadores[vez].push_back(saque.front()); saque.pop();
            vez = proximo(vez);
        } else if (pri.num == 1){
            jogadores[vez].push_back(saque.front()); saque.pop();
            vez = proximo(vez);
        } else if (pri.num == 11){
            vez = proximo(vez);
        }

        // Iniciar jogo
        while (true){
            carta topo = descarte.top();

            bool jogou = false;
            carta jogada;

            // tenta jogar
            for (auto it = jogadores[vez].begin(); it != jogadores[vez].end(); ++it){
                if (it->num == topo.num || it->naipe == topo.naipe){
                    jogada = *it;
                    jogadores[vez].erase(it);
                    descarte.push(jogada);
                    jogou = true;
                    break;
                }
            }

            if (!jogou){
                carta s = saque.front(); saque.pop();

                if (s.num == topo.num || s.naipe == topo.naipe){
                    jogada = s;
                    descarte.push(s);
                    jogou = true;
                } else {
                    jogadores[vez].push_back(s);
                }
            }

            sort(jogadores[vez].rbegin(), jogadores[vez].rend());

            // vitória
            if (jogou && jogadores[vez].empty()){
                cout << vez+1 << '\n';
                break;
            }

            if (jogou){
                if (jogada.num == 12){ // dama
                    direcao = !direcao;
                    vez = proximo(vez);
                }
                else if (jogada.num == 7){ // compra 2 e pula
                    ll nx = proximo(vez);
                    for (int i = 0; i < 2 && !saque.empty(); i++){
                        jogadores[nx].push_back(saque.front());
                        saque.pop();
                    }
                    sort(jogadores[nx].rbegin(), jogadores[nx].rend());
                    vez = proximo(nx); // pula
                }
                else if (jogada.num == 1){ // compra 1 e pula
                    ll nx = proximo(vez);
                    if (!saque.empty()){
                        jogadores[nx].push_back(saque.front());
                        saque.pop();
                    }
                    sort(jogadores[nx].rbegin(), jogadores[nx].rend());
                    vez = proximo(nx);
                }
                else if (jogada.num == 11){ // valete
                    vez = pular(vez);
                }
                else{
                    vez = proximo(vez);
                }
            }
            else{
                vez = proximo(vez);
            }
        }
    }

    return 0;
}
