#include <bits/stdc++.h>
#include <cctype>
#include <stack>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  ll caso{};
  while(t--){
    stack<string> pile, hand;
    ll i=27;
    while(i--){
      string x; cin >> x;
      pile.push(x);
    }
    i=25;
    while(i--){
      string x; cin >> x;
      hand.push(x);
    }
    ll y{};
    i=3;
    while(i--){
      string top_card = pile.top(); pile.pop();
      ll x;
      if (isdigit(top_card[0])) x = top_card[0]-'0';
      else x=10;
      y+=x;
      ll r=10-x;
      while(r--) pile.pop();
    }
    stack<string> temp;
    while(!hand.empty()){
      temp.push(hand.top()); hand.pop();
    }

    while(!temp.empty()){
      pile.push(temp.top()); temp.pop();
    }
    ll remover = pile.size() - y;
    while(remover--) pile.pop();

    cout << "Case " << ++caso << ": " << pile.top() << '\n';
  }

  return 0;
}

