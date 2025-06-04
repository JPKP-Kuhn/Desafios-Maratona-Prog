#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll directors{};
  cin >> directors;
  ll maxMeetingDuration{};
  cin >> maxMeetingDuration;

  // Primeiro caso de teste -> 16 * 7 = 112, + 6 = 116, tá dentro
  // 1 e 10, só um diretor, não tem nenhuma pausa entre as falas
  ll tempo = maxMeetingDuration - (directors-1);
  cout << tempo/directors << '\n';

  return 0;
}

