# Introdução
Livro criado com o intuito de ser um guia para ajudar a equipe durante a realização dos desafios da maratona. Ele possui exemplos de algoritmos e algumas dicas para certos problemas.
Para uma maratona de programação, pode ser utilizada linguagens de programação como Python, C, C++, Java, entre outras. No entanto é recomendável aprender C++. 

Alguns códigos deste livro estarão em Python ou C++.

## .vimrc
Configuração do arquivo `.vimrc` para melhorar o uso do editor durante a maratona.
```vim
" Comments in Vimscript start with a `"`.

" If you open this file in Vim, it'll be syntax highlighted for you.

" Vim is based on Vi. Setting `nocompatible` switches from the default
" Vi-compatibility mode and enables useful Vim functionality. This
" configuration option turns out not to be necessary for the file named
" '~/.vimrc', because Vim automatically enters nocompatible mode if that file
" is present. But we're including it here just in case this config file is
" loaded some other way (e.g. saved as `foo`, and then Vim started with
" `vim -u foo`).
set nocompatible

" Turn on syntax highlighting.
syntax on

" Disable the default Vim startup message.
set shortmess+=I

" Show line numbers.
set number

" This enables relative line numbering mode. With both number and
" relativenumber enabled, the current line shows the true line number, while
" all other lines (above and below) are numbered relative to the current line.
" This is useful because you can tell, at a glance, what count is needed to
" jump up or down to a particular line, by {count}k to go up or {count}j to go
" down.
set relativenumber

" Always show the status line at the bottom, even if you only have one window open.
set laststatus=2

" The backspace key has slightly unintuitive behavior by default. For example,
" by default, you can't backspace before the insertion point set with 'i'.
" This configuration makes backspace behave more reasonably, in that you can
" backspace over anything.
set backspace=indent,eol,start

" By default, Vim doesn't let you hide a buffer (i.e. have a buffer that isn't
" shown in any window) that has unsaved changes. This is to prevent you from "
" forgetting about unsaved changes and then quitting e.g. via `:qa!`. We find
" hidden buffers helpful enough to disable this protection. See `:help hidden`
" for more information on this.
set hidden

" This setting makes search case-insensitive when all characters in the string
" being searched are lowercase. However, the search becomes case-sensitive if
" it contains any capital letters. This makes searching more convenient.
set ignorecase
set smartcase

" Enable searching as you type, rather than waiting till you press enter.
set incsearch

" Unbind some useless/annoying default key bindings.
nmap Q <Nop> " 'Q' in normal mode enters Ex mode. You almost never want this.

" Disable audible bell because it's annoying.
set noerrorbells visualbell t_vb=

" Enable mouse support. You should avoid relying on this too much, but it can
" sometimes be convenient.
set mouse+=a

" Try to prevent bad habits like using the arrow keys for movement. This is
" not the only possible bad habit. For example, holding down the h/j/k/l keys
" for movement, rather than using more efficient movement commands, is also a
" bad habit. The former is enforceable through a .vimrc, while we don't know
" how to prevent the latter.
" Do this in normal mode...
nnoremap <Left>  :echoe "Use h"<CR>
nnoremap <Right> :echoe "Use l"<CR>
nnoremap <Up>    :echoe "Use k"<CR>
nnoremap <Down>  :echoe "Use j"<CR>
" ...and in insert mode
inoremap <Left>  <ESC>:echoe "Use h"<CR>
inoremap <Right> <ESC>:echoe "Use l"<CR>
inoremap <Up>    <ESC>:echoe "Use k"<CR>
inoremap <Down>  <ESC>:echoe "Use j"<CR>
```


## Matemática
Apenas algumas dicas:

- Soma de uma Progressão Aritmética: [Missing Number](https://cses.fi/problemset/task/1083/)
```c++
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
```python
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
```python
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
```python
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

#### Rotacionar uma matriz
##### Rotação 90° Horária (Clockwise)
- Fórmula: novo[j][n-1-i] = original[i][j]
Algoritmo:

1. Transpor a matriz (trocar linhas por colunas)
2. Reverter cada linha

##### Rotação 90° Anti-horária (Counterclockwise)
- Fórmula: novo[n-1-j][i] = original[i][j]
Algoritmo:

1. Transpor a matriz (trocar linhas por colunas)
2. Reverter cada coluna

Tempo O(n²)
 ```c++
// Para usar rapidamente em contest
void rotateCW(vector<vector<int>>& m) {
    int n = m.size();
    for(int i = 0; i < n; ++i) 
        for(int j = i + 1; j < n; ++j) 
            swap(m[i][j], m[j][i]);
    for(int i = 0; i < n; ++i) 
        reverse(m[i].begin(), m[i].end());
}

void rotateCCW(vector<vector<int>>& m) {
    int n = m.size();
    for(int i = 0; i < n; ++i) 
        for(int j = i + 1; j < n; ++j) 
            swap(m[i][j], m[j][i]);
    for(int j = 0; j < n; ++j) 
        for(int i = 0; i < n/2; ++i) 
            swap(m[i][j], m[n-1-i][j]);
}
```
[codeforces](https://codeforces.com/gym/105327/problem/E)
Precisa contar quantas vezes precisou girar a matriz para estar nas regras do problema.
```c++
#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;

bool rightBox (ll n, vector<vll>& casejewel) {
  for (ll i=0;i<n;i++){
    for (ll j=0;j<n-1;j++){
      // Se encontrar um número que é maior que o atual, na próxima coluna ou próxima linhas
      // Ou seja, os números devem ser crescentes.
      if (casejewel[i][j] >= casejewel[i][j+1]) return false;
      if (casejewel[j][i] >= casejewel[j+1][i]) return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n{};
  cin >> n;
  vector<vll> casejewel(n, vll(n));

  for (ll i=0;i<n;i++){
    for (ll j=0;j<n;j++){
      cin >> casejewel[i][j];
    }
  }

  ll rotations{};
  while(!rightBox(n, casejewel) && rotations<4){

    // Rotates couterclockwise
    for (ll i = 0; i < n; i++) {
      for (ll j = i + 1; j < n; j++) {
        swap(casejewel[i][j], casejewel[j][i]);
      }
    }
    for (ll j = 0; j<n; j++) {
      for (ll i = 0; i<n/2;i++){
        swap(casejewel[i][j], casejewel[n - 1 - i][j]);
      }
    }

    rotations++;
  }

  cout << rotations << '\n';


  return 0;
}
```

## Fila, queue
Operam como uma FIFO (First-in First-out)
```python
from collections import deque

queue = deque()
queue.append('a')
print(queue.popleft()) #Output 'a'
```

[Throwing cards away I](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1876)
Dado um número, terá um deck de cartas de 1 (Primeira no topo) até este número (Última carta do deck), descarte a carta do topo e mova a nova que agora está no topo para o final do deck.
```c++
#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
using namespace std;
using ll = long long;

int n;
int main() {
  for (;;) {
    scanf("%d", &n);
    if (n == 0) {break;}

    queue<int> cards;
    for (int i = 1; i <= n; i++) {
      cards.push(i);
    }

    queue<int> discarded;
    int c, d;
    while(cards.size() > 1) {
      c = cards.front();
      cards.pop();
      discarded.push(c);
      d = cards.front();
      cards.pop();
      cards.push(d);
    }

    printf("Discarded cards:");
    int s = discarded.size();
    for (int i = 0; i < s-1; i++){
        printf(" %d,", discarded.front());
        discarded.pop();
    }
    printf(" %d\n", discarded.front());
    printf("Remaining card: %d\n", cards.front());
  }
  return 0;
}
```
### Priority_queue
Semelhante a uma fila, mas seu primeiro elemento sempre é o maior que ela contém.
[Add All](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1895)
Calcular o custo mínimo para somar todos os números de uma sequência. Exemplo 1 2 3, terá saída 9, pois 1 + 2 = 3 e 3 + 3 = 6, o custo será o calor das operações, 3 + 6
```c++
#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll n;
int main() {
  while (cin >> n && n != 0) {
    priority_queue<ll, vector<ll>, greater<ll>> somas;
    ll x;
    for (ll i = 0; i<n;i++) {
      cin >> x;
      somas.push(x);
    }

    ll tot_cost = 0;
    while (somas.size() > 1) {
      ll a = somas.top(); somas.pop();
      ll b = somas.top(); somas.pop();
      ll cost = a + b;
      tot_cost += cost;
      somas.push(cost);
    }
    cout << tot_cost << endl;
  }
  return 0;
}
```

## Pilha, stack
Operam como uma LIFO (Last-in, First-out)
[Rails](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=455)
Basicamente, recebe uma pilha de números e tem que saber se ela pode realmente ser uma pilha com números crescentes ou descrescentes. Yes se for 1 2 3 4 5 ou 5 4 3 2 1, mas No se for 5 4 1 2 3
```c++
#include <bits/stdc++.h>
#include <stack>
using namespace std;
using ll = long long;

int main() {
  ll n;

  while(cin >> n && n != 0) {
    while (true) {
      vector<ll> alvo(n);
      bool possivel = true;

      cin >> alvo[0];
      if (alvo[0] == 0) break; // fim do bloco
      for (ll i =1;i < n; i++){
        cin >> alvo[i];
      }

      stack<ll> estacao;
      ll atual = 1; // Próximo vagão de A

      for (ll i =0; i < n; i++) {
        ll desejado = alvo[i];

        // Empilha até o desejado apracerer no topo
        while (atual <= n && (estacao.empty() || estacao.top() != desejado)) {
          estacao.push(atual);
          atual++;
        }

        if (estacao.top() == desejado && !estacao.empty()) {
          estacao.pop();
        } else {
          possivel = false;
          break;
        }
      }
      // Acabou o bloco
      cout << (possivel ? "Yes" : "No") << endl;
    }
    cout << endl;
  }
  return 0;
}
```
## Ad hoc
São problemas que não envolvem nenhuma técnica de programação específica, nem um estrutura de dados, mas sim, raciocínio lógico e uma elaboração direta do algoritmo. Eles envolvem também ordenação dos objetos para posterior manipulação

### Ordenação de uma struct com sort
[Quem vai ser Reprovado](https://judge.beecrowd.com/pt/problems/view/2134)
Basicamente ordenar os alunos em ordem crescente pelo número de questões corretas e, caso seja o mesmo número, então entre eles vale uma ordem lexicográfica, como a ordem alfabética por exemplo.
```c++
#include <bits/stdc++.h>
#include <ios>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

typedef struct aluno {
  string nome;
  int problemas;

} Aluno;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int instacia {1};

  while (cin >> n) {

    vector<Aluno> alunos(n);

    for (int i=0; i<n; i++) {
      cin >> alunos[i].nome >> alunos[i].problemas;
    }

    // Ordenação em ordem crscente
    sort(alunos.begin(), alunos.end(), [](const Aluno& a, const Aluno& b) {
      if (a.problemas == b.problemas) {  // Se os alunos resolveram o mesmo número de problemas
        return a.nome > b.nome;          // Faz a comparação lexicográfica, ou seja, pela ordem alfabética
        // será true se a.nome vem depois de b.nome no alfabeto, e assim o a.nome deve vir antes de b.nome
        // Por exemplo, a.nome = "João"; b.nome = "Ana", retornará true. Então a ordem fica Z-A
      }
      return a.problemas < b.problemas; // Assim organiza em ordem alfabética de A-Z
    });

    cout << "Instancia " << instacia << '\n';
    instacia++;
    cout << alunos[0].nome << '\n';
    cout << '\n';
  }

  return 0;
}
```
### Algumas funções úteis para organizar os dados
criar listas ou fazer rearranjos.

#### Função next_permutation
Rearranja os elementos para a próxima lexicográfica permutação que é maior que a anterior. Também pode ser com números, exemplo: {1, 2, 3} essa é a menor e a maior é {3, 2 ,1} se usar o next_permutation de novo na maior, então volta para a menor.
```c++
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string test;
  cin >> test;
  while(test != "#"){
    if (next_permutation(test.begin(), test.end())){ // Se for possível foramar uma nova permutação, então o faz
      cout << test << '\n';
    } else {                                        // Não é possível formar uma nova permutação, pois já é a última
      cout << "No Successor\n";
    }
    cin >> test;
  }

  return 0;
}
```

#### Função nth_element
Rearranjas os elementos de um intervalo, de forma que a nth posição estará na posição correta se fosse feito um sort() na lista inteira ao invés do nth_element.
Útil quando eu não preciso organizar uma lista inteira, mas apenas algum elemento dela, como por exemplo, para calcular a mediana:

```c++
int main() {
  ll n{};
  vll valores;

  while(cin >> n){

    valores.push_back(n);

    ll size = valores.size();
    vll temp = valores;

    // Mediana
    if (size % 2 == 1) { // Tamanho ímpar de valores
      nth_element(temp.begin(), temp.begin()+size/2, temp.end()); // Apenas o elemento do meio estará na posição correta
      cout << temp[size/2] << '\n';
    } else {             // Tamanho par de valores
      nth_element(temp.begin(), temp.begin()+ size/2 - 1, temp.end());
      ll a = temp[size/2 - 1];
      nth_element(temp.begin(), temp.begin()+size/2, temp.end());
      ll b = temp[size/2];
      cout  << (a+b)/2 << '\n';
    }
  }
  return 0;
}
```

## Árvores
Estrutura que possui uma organização hierárquica entre seus elementos

### [Subordinates](https://cses.fi/problemset/task/1674)
Dada a estrutura de uma empresa, calcule para cada empregado, os seus subordinados
```c++
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

const ll maxn = 200010;
ll n;
vector<ll> employers[maxn];
vector<ll> ns (maxn, 0); // Número de subordinados
vector<bool> visited (maxn, false);

ll dfs(ll node) {
  ll count = 0;

  visited[node] = true;

  for (ll i : employers[node]) {
    if (! visited[i]) {
      count += 1 + dfs(i); // Assim count recebe também os filhos e precisa de um return para isso
    }
  }
  ns[node] = count;
  return count;
}

int main() {
  cin >> n;
  ll x;

  for (ll i = 2; i <= n;i++){
    cin >> x;
    x--;
    employers[x].push_back(i-1);
  }

  dfs(0);

  for (ll i = 0; i < n; i++) {
    cout << ns[i] << ' ';
  }
  cout << endl;

  return 0;
}
```
### [Decomposição de centróide](https://usaco-guide.translate.goog/plat/centroid?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt&_x_tr_pto=tc&lang=cpp)
Decomposição de uma árvore para calcular seus caminhos
```c++
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 200010;

int n;
vector<int> adj[maxn];
int subtree_size[maxn];

int get_subtree_size(int node, int parent = -1) {
	int &res = subtree_size[node];
	res = 1;
	for (int i : adj[node]) {
		if (i == parent) { continue; }
		res += get_subtree_size(i, node);
	}
	return res;
}

int get_centroid(int node, int parent = -1) {
	for (int i : adj[node]) {
		if (i == parent) { continue; }

		if (subtree_size[i] * 2 > n) { return get_centroid(i, node); }
	}
	return node;
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	get_subtree_size(0);
	cout << get_centroid(0) + 1 << endl;
}
```

## Grafos
Uma lista que representa a conectividade entre nós.
### [BFS](https://cp-algorithms.com/graph/breadth-first-search.html) (Breadth-first search) 
Algoritmo de busca em largura, ajuda a descobrir a menor distância entre um nó de origem e um de destino

```c++
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
```python
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
```c++
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
```c++
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
```c++
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
- [USACO](https://usaco.guide/)
