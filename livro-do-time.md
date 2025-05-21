# Introdução
Livro criado com o intuito de ser um guia para ajudar a equipe durante a realização dos desafios da maratona. Ele possui exemplos de algoritmos e algumas dicas para certos problemas.
Para uma maratona de programação, pode ser utilizada linguagens de programação como Python, C, C++, Java, entre outras. No entanto é recomendável aprender C++. 

Alguns códigos deste livro estarão em Python ou C++.

## Matemática
Apenas algumas dicas:

- Soma de uma Progressão Aritmética: [Missing Number](https://cses.fi/problemset/task/1083/)
```
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    // Soma todos os valores até n
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    for (int i = 1; i <= n - 1; i++) {
        int x;
        // Subtrai os valores os valores da entrada, pois queremos descobrir qual número está faltando
        cin >> x;
        sum -= x;
    }
    cout << sum << "\n";
}
```

- Verificar se dois pontos estão na mesma linha, coluna ou diagonal: [Dama - Beecrowd 1087](https://judge.beecrowd.com/pt/problems/view/1087)
```
# Movimentos da dama num tabuleiro de xadrez

# Verifica se está na mesma diagonal
def diagonal(dama, destino):
    if abs(dama[0] - destino[0]) == abs(dama[1] - destino[1]):
        return True
    else:
        return False

# Movimentos
def movimentos(dama, destino):
    move = 0
    if dama == destino:
        return move
    # Mesma linha ou mesma coluna ou diagonal
    elif dama[0] == destino[0] or dama[1] == destino[1] or diagonal(dama, destino):
        move += 1
        return move
    else:
        move += 2
        return move
        

if __name__ == "__main__":
    tabuleiro = [[0] * 9 for i in range(9)]

    while True:
        entrada = input().split()
        dama = list(map(int, entrada[:2]))
        destino = list(map(int, entrada[2:]))

        tabuleiro[int(dama[0])][int(dama[1])] = 1
        tabuleiro[int(destino[0])][int(destino[1])] = 1

        if int(dama[0]) == 0:
            break

        print(movimentos(dama, destino))

```

- Verificar quantos números primos existem até n. [Beecrowd 1221](https://judge.beecrowd.com/pt/problems/view/1221)
```
import math
entrada = int(input())

def ver_primo(x):
    if x == 1:
        return "Not Prime"
    else:
        raiz = int(math.sqrt(x)) # Só é necessário verificar até a raiz quadrada de n
        for i in range(2, raiz+1):
            if x % i == 0:
                return "Not Prime"
    return "Prime"

while entrada > 0:
    x = int(input())

    print(ver_primo(x))

    entrada -= 1

```

## Grafos
Uma lista que representa a conectividade entre nós.
### [BFS](https://cp-algorithms.com/graph/breadth-first-search.html) (Breadth-first search) 
Algoritmo de busca em largura, ajuda a descobrir a menor distância entre um nó de origem e um de destino

```
vector<vector<int>> adj;  // Reoresentação de uma lista de adjacência, grafo não direcionado
int n; // number of nodes
int s; // source vertex

queue<int> q; // Fila para BFS
vector<bool> used(n); // Vetor para saber os nós que já foram visitados
vector<int> d(n), p(n); // vector d armazenará a distância da origem; p armazenará quem é o nó pai

q.push(s);
used[s] = true;
p[s] = -1; // Pai do nó de origem pode ser -1 ou 0
while (!q.empty()) {
    // Retira o primeiro elemento da lista, na primeira vez é o próprio nó de origem
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (!used[u]) { // Achou um nó filho que ainda não foi verificado
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            p[u] = v;
        }
    }
}

// Se tivermos que restaurar e exibir o caminho mais curto da fonte até algum vértice  u, isso pode ser feito da seguinte maneira:
if (!used[u]) {
    cout << "No path!";
} else {
    vector<int> path;
    for (int v = u; v != -1; v = p[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int v : path)
        cout << v << " ";
}
```
### [DFS](https://cp-algorithms.com/graph/depth-first-search.html) (Depth First Search)
Algoritmo de busca profunda, primeiro vai até a última conexão de um grafo
```
vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices

vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}
```
Esta é a implementação mais simples da Busca em Profundidade. Conforme descrito nas aplicações, pode ser útil calcular também os tempos de entrada e saída e a cor do vértice. Coloriremos todos os vértices com a cor 0, se não os tivermos visitado, com a cor 1, se os tivermos visitado, e com a cor 2, se já tivermos saído do vértice.

Aqui está uma implementação genérica que também calcula esses valores:
```
vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices

vector<int> color;

vector<int> time_in, time_out;
int dfs_timer = 0;

void dfs(int v) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (int u : adj[v])
        if (color[u] == 0)
            dfs(u);
    color[v] = 2;
    time_out[v] = dfs_timer++;
}
```

## Referências -
- Todos os desafios contidos neste [repositório](https://github.com/JPKP-Kuhn/Desafios-Maratona-Prog)
- [Competitive Programing 3, by Halim](https://files.gitter.im/SamZhangQingChuan/sam/DA1g/Steven-Halim_-Felix-Halim-Competitive-Programming-3_-The-New-Lower-Bound-of-Programming-Contests-Lulu.com-_2013_.pdf)
- [Competitive Programmer’s Handbook](https://cses.fi/book/book.pdf)
- [Algorithms for Competitive Programming](https://cp-algorithms.com/index.html)
