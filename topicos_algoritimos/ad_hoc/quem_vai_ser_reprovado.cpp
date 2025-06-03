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

    sort(alunos.begin(), alunos.end(), [](const Aluno& a, const Aluno& b) {
      if (a.problemas == b.problemas) {
        return a.nome > b.nome;
      }
      return a.problemas < b.problemas;
    });

    cout << "Instancia " << instacia << '\n';
    instacia++;
    cout << alunos[0].nome << '\n';
    cout << '\n';
  }

  return 0;
}

