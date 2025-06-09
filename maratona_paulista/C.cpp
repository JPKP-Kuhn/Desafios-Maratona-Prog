#include <bits/stdc++.h>
#include <ios>
#include <vector>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAXN = pow(10, 5) + 10;

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

    vector<Point> polygon = {{0, 100}, {100, 0}, {200, 0}, {100, -100}, {0, -100}, {-100, 0}, {-200, 0}, {-100, 100}};

    if (point_in_polygon(point, polygon)){
      cout << "S\n";
    } else {
      cout << "N\n";
    }
  }



  return 0;
}

