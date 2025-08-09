# Introdução
Livro criado com o intuito de ser um guia para ajudar a equipe durante a realização dos desafios da maratona. Ele possui exemplos de algoritmos e algumas dicas para certos problemas.
Para uma maratona de programação, pode ser utilizada linguagens de programação como Python, C, C++, Java, entre outras. No entanto é recomendável aprender C++. 

Alguns códigos deste livro estarão em Python ou C++.

## .vimrc
Configuração do arquivo `.vimrc` para melhorar o uso do editor durante a maratona.
```vim
set autoindent
set clipboard=unnamedplus
set et
set incsearch
set number
set relativenumber
set shiftwidth=4
set showcmd
set smarttab
set softtabstop=4
set wildmenu
set mouse="a"

nnoremap ; :
vnoremap ; :

nnoremap J }
nnoremap K {
vnoremap J }
vnoremap K {

nnoremap <A-h> <C-w>h
nnoremap <A-j> <C-w>j
nnoremap <A-k> <C-w>k
nnoremap <A-l> <C-w>l
```

## Template para código C++
```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = 1e5 + 10;// Range seguro para vetores e arrays
const ll INF = 1e18+5;   // PD e inicialização de valor mínimo

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}

```

## Matemática
Apenas algumas dicas:

- Soma de uma Progressão Aritmética: [Missing Number](https://cses.fi/problemset/task/1083/)
```c++
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

### Método da Bisecção
Para encontrar as raízes de uma função. Teorema de Bolzano, usa busca binária.
- Uma função contínua em [a, b], se f(a) < 0 e f(b) > 0, então existe um x tal que f(x) = 0.
Com essa ideia acima é possível fazer um busca binária para encontrar as raízes da função.

```c++
using lld = long double;
const lld EPS = 1e-9;
// Equação a ser resolvida
// p ∗ e−x + q ∗ sin(x) + r ∗ cos(x) + s ∗ tan(x) + t ∗ x2 + u = 0

lld p, q, r, s, t, u;
// Determinar x
double x;

// Minha função
lld f(lld x){
  return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u; 
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> p >> q >> r >> s >> t >> u){ // Vários casos de teste até EOF
    // intervalo, 0 <= x <= 1
    lld a = 0.0, b = 1.0;
    // O teorema de Bolzano (valor intermediário) foi satisfeito? 
    // f(a0) * f(b0) < 0 -> existe troca de sinal no intervalo dado e, portanto
    // existe raiz nele.
    int bolzano_ok = (f(a)*f(b) > 0?0:1);
    if (!bolzano_ok) {
      cout << "No solution\n";
      continue;
    }
    if (fabs(f(a)) < EPS || fabs(f(b)) < EPS){
      cout << fixed << setprecision(4) << (f(a)==0 ? a : b) << '\n';
      continue;
    }

    // Método da bissecção
    // Busca binária
    while (b - a > EPS){
      lld pm = (a + b)/2.0;
      if (fabs(f(pm)) < EPS){
        break;
      }
      if (f(a)*f(pm) < 0){
        b = pm; // Solução está a esquerda
      } else {
        a = pm; // Solução está a direita
      }
    }
    cout << fixed << setprecision(4) << (a+b)/2.0 << '\n';
  }
  return 0;
}
```

### Geometria Analítica
 O fato de o máximo divisor comum (MDC) entre as diferenças das coordenadas x e y de dois pontos em um plano cartesiano ser igual a 1, ou seja, mdc(x₂ - x₁, y₂ - y₁) = 1, é um conceito fundamental na geometria dos pontos de grade. Isso significa que não há outros pontos de grade no segmento de reta que conecta esses dois pontos, além dos próprios pontos finais.

### Funções trigonométricas;
sin(), cos() e tan() retornam double e esperam o ângulo em radianos, portanto:
```c++
double angle = 45;
double rad = angle * M_PI / 180.0;
```

### Exponenciação Rápida
É possível dividir a exponenciação em partes, ao invés de fazer a¹⁴ é possível dividir em a⁸ * a⁴ * a² assim podemos também aproveitar a representação binária do expoente
```c++
int expRapida(int base, long long exp, int mod){
  int res = 1;
  for(int i=0; i < 63; i++){
    if(exp&(1LL << i)) 
      res = (res*1LL*base)%mod;
    base = (base*1LL*base)%mod;
  }
  return res;
}
```
Ou mais simples pode ser:
```c++
int expRapida(int base, long long exp, int mod){
  int res = 1;
  while(exp>0){
    if(exp&1LL) 
      res = (res*1LL*base)%mod;
    base = (base*1LL*base)%mod;
    exp = exp>>1;
  }
  return res;
}
```
Com isso também será possível calcular o inverso modular facilmente
```c++
int invMod(int a, int mod){
  return expRapida(a, mod-2, mod);
}
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
## Backtracking
Envolve justamente tentar um caminho e voltar atrás, sendo como uma força bruta até achar um caminho possível. Utiliza recursão.

Dado duas peças de dominó, uma a esquerda para começo e uma a direita para o fim e com um espaço entre elas. Utilize algumas outras peças deste dominó para saber se é possível formar um caminho conectando a esquerda com a diretia, usando as regrs do jogo para conectar.
```c++
ll n, m;
pair<ll, ll> left_end;
pair<ll, ll> right_end;
vector<pair<ll, ll>> domino;
vector<pair<ll, ll>> caminho_correto;
vector<bool> usada;
bool resposta = false;

void backtracking(){
  if (resposta) return;
  // Encaixo as peças uma por uma, salvo quais peças funcionaram, para poder depois recuar, backtracking
  if (caminho_correto.size() == n+1){ // n+1 porque a peça left já está em caminho_correto
    if (caminho_correto.back().second == right_end.first){
      cout << "Caminho correto\n";
      resposta = true;
    }
    return;
  }

  ll ult_num = caminho_correto.back().second;

  for (ll i =0; i<m; i++){
    if (!usada[i]){
      auto [a, b] = domino[i];

      if (a == ult_num){
        usada[i] = true;
        caminho_correto.push_back({a, b});
        cout << "Colocando a peça: " << a << ' ' << b << '\n';
        backtracking();
        // Se não der certo, retorna;
        cout << "Não funcionou com a\n";
        caminho_correto.pop_back();
        usada[i] = false;
      }
      else if (b == ult_num){
        usada[i] = true;
        caminho_correto.push_back({b, a});
        cout << "Colocando a peça: " << b << ' ' << a << '\n';
        backtracking();
        // Se não der certo, retorna;
        cout << "Não funcionou com b\n";
        caminho_correto.pop_back();
        usada[i] = false;
      }
      cout << "Caminho: \n";
      for (auto [x, y] : caminho_correto){
        cout << x << ' ' << y << '\n';
      }
      cout << right_end.first << ' ' << right_end.second << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  while (n!=0) {
    cin >> m;
    // left peça de começo
    ll a, b;
    cin >> a >> b;
    left_end = make_pair(a, b);

    // right peça no fim
    ll c, d;
    cin >> c >> d;
    right_end = make_pair(c, d);

    // Limpar para cada caso de teste
    domino.clear();
    domino.resize(m);
    caminho_correto.clear();
    usada.assign(m, false);
    resposta = false;
    for (ll i=0; i < m; i++){
      ll x, y;
      cin >> x >> y;
      domino[i] = make_pair(x, y);
    }
    caminho_correto.push_back(left_end);
    backtracking();

    cout << (resposta ? "YES\n" : "NO\n");
    cin >> n; // Novo caso de teste
  }

  return 0;
}
```

## Programação Dinâmica (PD, ou DP)
utilizar um vetor ou outra estrutura para guardar valores já calculados e assim otimizar a conta. Caraterística principal é a recursão.

Calcular número de fibonacci
```c++
ll pd[MOD];     // MOD, pois a sequência pode crescer muito
bool found[MOD];
 
ll dp(ll n){
  if (found[n]) return pd[n];
  if (n == 0) return 0;
  if (n == 1) return 1;

  found[n] = true;
  return pd[n] = (dp(n-1) + dp(n-2))%MOD;
}
pd[0] = 0; pd[1] = 1; // É necessário incializar a pd;
 
```
### Soma prefixada
Tem um vetor, quero somar rapidamente os valores de [i, j]. Para somar rapidamente esse intervalo, guardo em um outro vetor as somas do início até o v[i].
```c++
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, q;
  cin >> n >> q;
  vll v(n+1); // soma[0] = 0
  for (ll i=1; i<=n; i++){
    cin >> v[i];
    // Aqui estou modificando o próprio vetor.
    v[i] += v[i-1]; // Soma acumulada 
  }
  while(q--){
    ll a, b;
    cin >> a >> b;
    cout << v[b] - v[a-1] << '\n'; // soma de v[a] até v[b];
  }
  return 0;
}
```
Outro exemplo:
```c++
// function to find the prefix sum array
vector<int> prefSum(vector<int> &arr) {
    int n = arr.size();
    
    // to store the prefix sum
    vector<int> prefixSum(n);
    // initialize the first element
    prefixSum[0] = arr[0];
    // Adding present element with previous element
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    
    return prefixSum;
}
int main() {
    vector<int> arr = {10, 20, 10, 5, 15};
    vector<int> prefixSum = prefSum(arr);
    for(auto i: prefixSum) {
        cout << i << " " ;
    }
    return 0;
}```

### 2D Prefix Sum
É uma soma prefixada, mas em uma matriz. Usada se for necessário somar todos os elementos de uma submatriz da matriz original. Cada elemento i,j  da matriz de soma prefixada representa a soma dos elementos de 0,0 até i,j.
```c++
vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
    int rows = mat.size(), cols = mat[0].size();
    // create prefix matrix of size 
    // (rows+1)x(cols+1) to simplify boundaries
    vector<vector<int>> pre(rows + 1, vector<int>(cols + 1, 0));
    // Build prefix matrix with 1-based indexing
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            pre[i][j] = mat[i - 1][j - 1] 
                      + pre[i - 1][j] 
                      + pre[i][j - 1] 
                      - pre[i - 1][j - 1];
        }
    }
    vector<int> result;
    // process each query using inclusion-exclusion
    for (auto &q : queries) {
        int topRow = q[0] + 1, leftCol = q[1] + 1;
        int bottomRow = q[2] + 1, rightCol = q[3] + 1;
        // get total area from (1,1) to (bottomRow, rightCol)
        int total = pre[bottomRow][rightCol];
        // subtract area above the submatrix
        int top = pre[topRow - 1][rightCol];
        // subtract area to the left of the submatrix
        int left = pre[bottomRow][leftCol - 1];
        // add back the overlapping top-left area,
        // which was subtracted twice
        int overlap = pre[topRow - 1][leftCol - 1];
        // final submatrix sum using inclusion-exclusion
        int sum = total - top - left + overlap;
        result.push_back(sum);
    }
    return result;
}
```

### MaxSubArraySum
Em uma array com números inteiros, encontrar a maior soma possível numa subarray. Por exemplo: {2, 3, -8, 7, -1, 2, 3}, terá maior soma a partir do 7 até o final, sendo 11.
```c++
int maxSubarraySum(vector<int> &arr) {
    // Stores the result (maximum sum found so far)
    int res = arr[0];           
    // Maximum sum of subarray ending at current position
    int maxEnding = arr[0];     
    for (int i = 1; i < arr.size(); i++) {
        // Either extend the previous subarray or start 
        // new from current element
        maxEnding = max(arr[i], maxEnding + arr[i]);

        // Update result if the new subarray sum is larger
        res = max(res, maxEnding);
    }
    return res;
```

### LCS - Sequência comum máxima
Dadas duas string, qual é o comprimento da maior subsequência comum entre elas.
```c++
// Returns length of LCS for s1[0..m-1], s2[0..n-1]
int lcs(string &s1, string &s2) {
    int m = s1.size();
    int n = s2.size();

    // Initializing a matrix of size (m+1)*(n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Building dp[m+1][n+1] in bottom-up fashion
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // dp[m][n] contains length of LCS for s1[0..m-1]
    // and s2[0..n-1]
    return dp[m][n];
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << lcs(s1, s2) << endl;
    return 0;
}
```

### Algumas funções úteis para organizar os dados
criar listas ou fazer rearranjos.

#### Função next_permutation
Rearranja os elementos para a próxima lexicográfica permutação que é maior que a anterior. Também pode ser com números, exemplo: {1, 2, 3} essa é a menor e a maior é {3, 2 ,1} se usar o next_permutation de novo na maior, então volta para a menor.
```c++
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

#### Verificar se é um palíndromo:
```c++
bool palindromo(const string& s) {
  for (ll j = 0; j < (ll)s.length() / 2; j++) {
    if (s[j] != s[s.length() - j - 1]) return false;
  }
  return true;
}
```

#### Criar um número em outra base numérica
Bases numéricas entre 2 e 9.
```c++
string to_base(ll i, ll base) {
  string res;
  while (i > 0) {
    res = char('0' + (i % base)) + res;
    i /= base;
  }
  return res;
}
```

## Árvores
Estrutura que possui uma organização hierárquica entre seus elementos

### [Subordinates](https://cses.fi/problemset/task/1674)
Dada a estrutura de uma empresa, calcule para cada empregado, os seus subordinados
```c++
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
### Trie
Estrutura de dados para guardar dinamicamente um conjunto de string. Funciona como uma árvore em que cada char da string é armazenado no nó. Basta seguir cada nó que se formará a string original. Strings que compartilham mesmo char, terão este char em comum.
```c++
class TrieNode
{
  public:
    // Array for children nodes of each node
    TrieNode *children[26];

    // for end of word
    bool isLeaf;

    TrieNode()
    {
        isLeaf = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};
  // Method to insert a key into the Trie
void insert(TrieNode *root, const string &key)
{
    // Initialize the curr pointer with the root node
    TrieNode *curr = root;
    // Iterate across the length of the string
    for (char c : key)
    {
        // Check if the node exists for the
        // current character in the Trie
        if (curr->children[c - 'a'] == nullptr)
        {
            // If node for current character does
            // not exist then make a new node
            TrieNode *newNode = new TrieNode();

            // Keep the reference for the newly
            // created node
            curr->children[c - 'a'] = newNode;
        }
        // Move the curr pointer to the
        // newly created node
        curr = curr->children[c - 'a'];
    }
    // Mark the end of the word
    curr->isLeaf = true;
}
// Method to search a key in the Trie
bool search(TrieNode *root, const string &key)
{
    if (root == nullptr)
    {
        return false;
    }
    // Initialize the curr pointer with the root node
    TrieNode *curr = root;

    // Iterate across the length of the string
    for (char c : key)
    {
        // Check if the node exists for the
        // current character in the Trie
        if (curr->children[c - 'a'] == nullptr)
            return false;
        // Move the curr pointer to the
        // already existing node for the
        // current character
        curr = curr->children[c - 'a'];
    }
    // Return true if the word exists
    // and is marked as ending
    return curr->isLeaf;
}
// Method to check if a prefix exists in the Trie
bool isPrefix(TrieNode *root, const string &prefix)
{
    // Initialize the curr pointer with the root node
    TrieNode *curr = root;
    // Iterate across the length of the prefix string
    for (char c : prefix)
    {
        // Check if the node exists for the current character in the Trie
        if (curr->children[c - 'a'] == nullptr)
            return false;

        // Move the curr pointer to the already existing node
        // for the current character
        curr = curr->children[c - 'a'];
    }
    // If we reach here, the prefix exists in the Trie
    return true;
  }
int main()
{
    // Create am example Trie
    TrieNode *root = new TrieNode();
    vector<string> arr = {"and", "ant", "do", "dad"};
    for (const string &s : arr)
    {
        insert(root, s);
    }
    // One by one search strings
    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string &s : searchKeys){
        
        if(search(root, s))
            cout << "true ";
        else
            cout << "false ";
    } 
    cout<<"\n";
    // One by one search for prefixes
    vector<string> prefixKeys = {"ge", "ba", "do", "de"};
    for (string &s : prefixKeys){
        
        if (isPrefix(root, s))
            cout << "true ";
        else
            cout << "false ";
    }
    return 0;
}
```

### [Decomposição de centróide](https://usaco-guide.translate.goog/plat/centroid?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt&_x_tr_pto=tc&lang=cpp)
Decomposição de uma árvore para calcular seus caminhos
```c++
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

### Ordenação topológica e algoritmo de Kahn
Deve ser usado num grafo direcionado acíclico, pois a ordenação topológica se baseia no grau de cada nó. Este grau é 0 se não tem nenhum nó apontando para ele, assim ele se torna o source do grafo. O algoritmo de Kahn usa BFS.

Geeksforgeeks -
```c++
// We mainly take input graph as a set of edges. This function is
// mainly a utility function to convert the edges to an adjacency
// list
vector<vector<int>> constructadj(int V,vector<vector<int>> &edges){
    
    // Graph represented as an adjacency list
    vector<vector<int> > adj(V);

    // Constructing adjacency list
    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }
    
    return adj;
}

// Function to return list containing vertices in
// Topological order.
vector<int> topologicalSort(int V, vector<vector<int> >& edges)
{
    vector<vector<int>> adj = constructadj(V,edges);
    
    // Vector to store indegree of each vertex
    vector<int> indegree(V);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }
    // Queue to store vertices with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        // Decrease indegree of adjacent vertices as the
        // current node is in topological order
        for (auto it : adj[node]) {
            indegree[it]--;

            // If indegree becomes 0, push it to the queue
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    // Check for cycle
    if (result.size() != V) {
        cout << "Graph contains cycle!" << endl;
        return {};
    }
    return result;
}
int main()
{
    // Number of nodes
    int V = 6;

    // Edges
    vector<vector<int> > edges
        = {{0, 1}, {1, 2}, {2, 3},
           {4, 5}, {5, 1}, {5, 2}};

    vector<int> result = topologicalSort(V, edges);

    // Displaying result
    for (auto i : result) {
        cout << i << " ";
    }
    return 0;
}
```

Exemplo de probleam resolvido com algoritmo de Kahn:
Manyfile, basicamente: tem que saber o tempo que leva para compilar um programa, sendo que tem arquivos que dependem de outros para serem compilados. Retorna -1 se é impossível, ou seja há um ciclo, arquivo 0 depende de 1 e 1 depende de 0, caso contrário retorna o tempo que levou, sendo que todos são compilados ao mesmo tempo, mas o total será aquele que depende de mais arquivos para ser compilado -
```c++
ll n;
vector<vll> adj;

ll digraph(ll v){  // Algoritmo de Kahn que verifica se há um ciclo
  vll degree(v, 0);
  queue<ll> q;
  vll level(v, 0);
  ll processed = 0;

  // Degree of vertices
  for (ll i = 0; i<v; i++){
    for (ll j : adj[i]){
      degree[j]++;
    }
  }
  // add degree 0 to the q
  for (ll i=0;i<v;i++){
    if (degree[i] == 0){
      q.push(i);
      level[i] = 1;
    }
  }

  ll maxTime{};
  while(!q.empty()){
    ll u = q.front();
    q.pop();
    processed++;
    maxTime = max(maxTime, level[u]);

    for (ll e : adj[u]){
      degree[e]--;
      if (degree[e] == 0){
        level[e] = level[u] + 1;
        q.push(e);
      }
    }
  }
  if (processed != v){ // If is a cicle, return -1;
    return -1;
  }
  return maxTime;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n){
    adj.clear();
    adj.resize(n);
    for (ll i=0; i<n; i++){
      ll m;
      cin >> m;
      for (ll j=0;j<m;j++){
        ll x;
        cin >> x;
        adj[i].push_back(--x);
      }
    }

    ll res = digraph(n);
    cout << res << '\n';
  }
  return 0;
}
```

## Geometria
Problemas que envolvem forams geométricas e plano cartesiano

### Ponto dentro de um polígono
Dada as coordenadas dos vértices de um polígono, e um ponto, quero descobrir se esse ponto está dentro, fora ou na borda
```c++
struct Point {
  ll x, y;
};

bool point_on_edge(Point p, Point a, Point b) {
    // Verifica se o ponto está na linha que passa por a e b
    ll cross = (p.y - a.y) * (b.x - a.x) - (p.x - a.x) * (b.y - a.y);
    if (cross != 0) return false; // Não está na linha
    
    // Verifica se está no segmento
    ll dot = (p.x - a.x) * (b.x - a.x) + (p.y - a.y) * (b.y - a.y);
    ll len_sq = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
    return dot >= 0 && dot <= len_sq;
}

bool point_in_polygon(Point point, vector<Point> polygon){
  ll num_vertices = polygon.size();

  // Verifica se está na borda
  for (ll i = 0; i < num_vertices; i++) {
    Point p1 = polygon[i];
    Point p2 = polygon[(i + 1) % num_vertices];
    if (point_on_edge(point, p1, p2)) {
      return true;
    }
  }

  Point p1 = polygon[0], p2;
  double x = point.x, y = point.y;
  bool inside = false;

  for (ll i=1; i<=num_vertices; i++) {
    p2 = polygon[i % num_vertices];

    if (y > min(p1.y, p2.y)) {
      if (y <= max(p1.y, p2.y)) {
        if (x <= max(p1.x, p2.x)) {
          double x_intersection = (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;

          if (p1.x == p2.x || x <= x_intersection) {
            inside = !inside;
          }
        }
      }
    }
    p1 = p2;
  }
  return inside;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t{};
  cin >> t;
  while (t--){
    ll x,y;
    cin >> x >> y;
    Point point = {x, y};
    // Polígono de interesse
    vector<Point> polygon = {{0, 100}, {100, 0}, {200, 0}, {100, -100}, {0, -100}, {-100, 0}, {-200, 0}, {-100, 100}};

    if (point_in_polygon(point, polygon)){
      cout << "S\n";
    } else {
      cout << "N\n";
    }
  }
  return 0;
}
```
## Teoria de jogos Combinatórios
### Jogo do Nim
```c++

/*
  Jogo do Nim - Análise por Nim-sum (XOR das pilhas)
  Regra normal: quem pega a última pedra vence.

  Teorema:
    - Se o XOR de todos os tamanhos de pilha (nim-sum) for 0 → posição perdedora.
    - Caso contrário → posição ganhadora.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; // número de pilhas
    cin >> n;

    vector<int> pilha(n);
    for (int i = 0; i < n; i++) cin >> pilha[i];

    int nim_sum = 0;
    for (int pedras : pilha) nim_sum ^= pedras;
    if (nim_sum == 0)
        cout << "PERDEDOR\n";  // posição perdedora para o primeiro jogador
    else
        cout << "GANHADOR\n";  // posição ganhadora para o primeiro jogador
    return 0;
}
```

Problema resolvido com jogo do Nim. Terão 3 pilhas de batata. Pode remover todas as batadas da pilha, ou um valor n, sendo 1 <= n <= min{pilha}, ou seja, uma entrada 5 4 2. Pode remover todas duma pilha, ou um valor entre 1 e 2(sendo este o menor dentre as 3). Ganha o que remover a última batata, você é o primeiro a jogar. Assim:
```c++
  if ((a ^ b ^ c) == 0){ // a b c são a quantidade de batata em cada pilha
    cout << "No\n"; // Não é possível vencer
  } else {
    cout << "Yes\n";
  }
```


## Referências -
- Todos os desafios contidos neste [repositório](https://github.com/JPKP-Kuhn/Desafios-Maratona-Prog)
- [Competitive Programing 3, by Halim](https://files.gitter.im/SamZhangQingChuan/sam/DA1g/Steven-Halim_-Felix-Halim-Competitive-Programming-3_-The-New-Lower-Bound-of-Programming-Contests-Lulu.com-_2013_.pdf)
- [Competitive Programmer’s Handbook](https://cses.fi/book/book.pdf)
- [Algorithms for Competitive Programming](https://cp-algorithms.com/index.html)
- [GeeksforGeeks](https://www.geeksforgeeks.org/)
- [USACO](https://usaco.guide/)
