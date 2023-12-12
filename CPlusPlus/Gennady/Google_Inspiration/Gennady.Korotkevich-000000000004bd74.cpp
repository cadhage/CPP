/**
 *    author:  tourist
 *    created: 09.06.2018 17:13:45       
**/
#include <bits/stdc++.h>

using namespace std;

struct point {
  long long x;
  long long y;
  long long z;

  point() { x = y = z = 0; }
  point(long long xx, long long yy, long long zz) : x(xx), y(yy), z(zz) { }

  inline point operator - (const point &other) const {
    return point(x - other.x, y - other.y, z - other.z);
  }

  inline point vmul(const point &other) const {
    return point(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
  }

  inline long long smul(const point &other) const {
    return x * other.x + y * other.y + z * other.z;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ":";
    int n;
    cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i].x >> p[i].y >> p[i].z;
    }
    vector<int> alive(n, 1);
    vector<int> res;
    int start = 0;
    for (int i = 1; i < n; i++) {
      if (p[i].z > p[start].z) {
        start = i;
      }
    }
    res.push_back(start);
    alive[start] = 0;
    int cont = -1;
    for (int i = 0; i < n; i++) {
      if (i == start) {
        continue;
      }
      if (cont == -1) {
        cont = i;
        continue;
      }
      long long vy = p[cont].y - p[start].y;
      long long vz = p[cont].z - p[start].z;
      long long iy = p[i].y - p[start].y;
      long long iz = p[i].z - p[start].z;
      long long vmul = vy * iz - vz * iy;
      if (vmul < 0) {
        cont = i;
      }
    }
    res.push_back(cont);
    alive[cont] = 0;
    for (int it = 0; it < n - 2; it++) {
      int a = res.back();
      int b = res[(int) res.size() - 2];
      int c = -1;
      point V;
      for (int i = 0; i < n; i++) {
        if (!alive[i]) {
          continue;
        }
        if (c == -1) {
          c = i;
        } else {
          if (V.smul(p[i]) > 0) {
            c = i;
          }
        }
        if (c == i) {
          V = (p[b] - p[a]).vmul(p[c] - p[a]);
          if (V.z < 0) {
            V.x = -V.x;
            V.y = -V.y;
            V.z = -V.z;
          }
        }
      }
      res.push_back(c);
      alive[c] = 0;
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < n; i++) {
      cout << " " << res[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}
