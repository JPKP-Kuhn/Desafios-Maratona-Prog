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

## Matrizes
Uma lista de listas

[Sudoku](https://judge.beecrowd.com/pt/problems/view/1383)
```
import sys

e = sys.stdin.read().splitlines()
n = int(e[0])
del e[0]
test = 0

# Verifica a matriz de Sudoku
def ver_sudoku(sudoku):
    # Verifica cada linha
    for i in range(len(sudoku)):
        for j in range(1, 10):
            v = sudoku[i].count(j)
            if v > 1:
                return "NAO"

    # Verifica cada coluna
    for i in range(len(sudoku)):
        coluna = []  # Reinicia a lista para cada coluna
        for j in range(len(sudoku)):
            coluna.append(sudoku[j][i])  # Adiciona o elemento da coluna atual

        for k in range(1, 10):
            c = coluna.count(k)
            if c > 1:
                return "NAO"

    # Verifica cada quadrante 3x3
    for i in range(3):
        for j in range(3):
            quadrante = []
            for k in range(3):
                for l in range(3):
                    quadrante.append(sudoku[i * 3 + k][j * 3 + l])  # Adiciona o elemento do quadrante atual
            for m in range(1, 10):
                q = quadrante.count(m)
                if q > 1:
                    return "NAO"

    return "SIM"

while n != 0:
    test += 1
    n -= 1
    sudoku = []

    # Lê a matriz de Sudoku
    for i in range(9):
        sudoku.append(list(map(int, e[0].split())))
        del e[0]

    result = ver_sudoku(sudoku)
    print("Instancia", test)
    print(result)
    print()
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

#### Um exemplo da implementação do BFS
Problema OBI [Fissura](https://olimpiada.ic.unicamp.br/pratique/ps/2020/f1/fissura/)
```
# Verificar a erupção de um vulcão
import sys

e = sys.stdin.read().splitlines()

n, f = map(int, e[0].split())
del e[0]

# Matriz do terreno
mat = [None] * n
for i in range(n):
    mat[i] = list(map(int, e[i]))

# Lista de teste para controlar a propagação da lava
lista = []
if mat[0][0] <= f:
    mat[0][0] = '*'
    lista.append((0,0))

# Para verificar as direções: para cima (-1, 0), para direita (0, 1), baixo (1, 0) e esquerda (0, -1)
dy = [-1, 0, 1, 0] # São vetores de direção
dx = [0, 1, 0, -1]

# Algoritimo de busca em largura (BFS) para simular a propagação de lava
while lista != []:
    u = lista.pop(0) # retira o primeiro elemento, FIFO
    i, j = u[0], u[1] # coordenadas atuais

    # Verifica as 4 direções adjacentes
    for d in range(4):
        iv = i + dy[d] # Nova coordenada y
        jv = j + dx[d] # Nova coordenada x

        # Verifica se a nova posição está dentro dos limites da matriz
        if iv >= 0 and iv <= n-1 and jv >= 0 and jv <= n-1:
            if mat[iv][jv] != '*' and mat[iv][jv] <= f:
                mat[iv][jv] = '*'
                lista.append((iv, jv)) # Adiciona a nova posição a lista de propagação


def converte_saida(matriz):
    return '\n'.join(''.join(map(str, linha)) for linha in matriz)
print(converte_saida(mat))

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

#### Aplicação de DFS
Problema [Counting Rooms](https://cses.fi/problemset/task/1192)
```
#include <bits/stdc++.h>
using namespace std;

// DFS function to mark all connected floor cells as visited
void dfs(vector<string>& mat, int i, int j, int n, int m) {
    // Check if current position is valid and is a floor
    if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == '#') {
        return;
    }
    
    mat[i][j] = '#';
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    // Explore all four directions
    for (int d = 0; d < 4; d++) {
        int nx = i + dx[d];
        int ny = j + dy[d];
        dfs(mat, nx, ny, n, m);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    
    int rooms = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '.') {
                rooms++;
                
                // Use DFS to mark all connected floor tiles as visited
                dfs(mat, i, j, n, m);
            }
        }
    }
    
    cout << rooms << endl;
    
    return 0;
}

```

## Referências -
- Todos os desafios contidos neste [repositório](https://github.com/JPKP-Kuhn/Desafios-Maratona-Prog)
- [Competitive Programing 3, by Halim](https://files.gitter.im/SamZhangQingChuan/sam/DA1g/Steven-Halim_-Felix-Halim-Competitive-Programming-3_-The-New-Lower-Bound-of-Programming-Contests-Lulu.com-_2013_.pdf)
- [Competitive Programmer’s Handbook](https://cses.fi/book/book.pdf)
- [Algorithms for Competitive Programming](https://cp-algorithms.com/index.html)
