#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
using namespace std;

#define lli long long int 
#define mk_p make_pair
#define fir first
#define sec second

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  lli total = 0, count = 0;
  for (lli i = 0; i<n; i++) 
  {
    total += (s1[i] == '*');
    count += (s2[i] =='*' && s2[i] != s1[i]);
  }

  cout << setprecision(2) << fixed;
  cout << 1.0*count / total << '\n';

  return 0;
}

