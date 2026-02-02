#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  double x; cin >> x;
  if (0 <= x && x <= 25){
    cout << "Interval [0,25]\n";
  } else if (25 < x && x <= 50){
    cout << "Interval (25,50]\n";
  } else if (50 < x && x <= 75){
    cout << "Interval (50,75]\n";
  } else if (75 < x && x <= 100){
    cout << "Interval (75,100]\n";
  } else {
    cout << "Out of Intervals\n";
  }
}
