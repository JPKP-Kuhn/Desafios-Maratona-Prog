#include <bits/stdc++.h>
using namespace std;

string s;
int i{};

void skip(){
  while(i < (int)s.size() && s[i]==' ') i++;
}

double expr();
double term();
double factor();

double expr(){
  double val = term();
  while(1){
    skip();
    if(i < (int)s.size() && s[i]=='+'){
      i++;
      val+=term();
    }else if (i< (int)s.size() && s[i]=='-'){
      i++;
      val-=term();
    } else break;
  }
  return val;
}

double term(){
  double val = factor();
  while(1){
    skip();
    if (i < (int)s.size() && s[i]=='*'){
      i++;
      val*=factor();
    } else if (i < (int)s.size() && s[i] == '/'){
      i++;
      val/=factor();
    } else break;
  }
  return val;
}

double factor(){
  skip();

  if (s[i] == '-'){
    i++;
    return -factor();
  }

  if (s[i] == '('){
    i++;
    double val = expr();
    i++;
    return val;
  }

  int start = i;
  while(i < (int)s.size() && (isdigit(s[i]) || s[i]=='.')) i++;

  return stod(s.substr(start, i - start));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  getline(cin, s);
  cout << fixed << setprecision(2) << expr() << '\n';

  return 0;
}

