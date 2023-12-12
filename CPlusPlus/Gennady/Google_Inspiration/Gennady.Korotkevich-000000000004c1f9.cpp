/**
 *    author:  tourist
 *    created: 09.06.2018 17:13:45       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int m, k;
    cin >> m >> k;
    map<pair<int,int>,int> mp;
    vector<int> x, y;
    int n = 0;
    vector<vector<pair<int,int>>> g;
    for (int i = 0; i < m; i++) {
      int xa, ya, xb, yb;
      cin >> xa >> ya >> xb >> yb;
      if (mp.find(make_pair(xa, ya)) == mp.end()) {
        x.push_back(xa);
        y.push_back(ya);
        mp[make_pair(xa, ya)] = n;
        n++;
        g.resize(n);
      }
      if (mp.find(make_pair(xb, yb)) == mp.end()) {
        x.push_back(xb);
        y.push_back(yb);
        mp[make_pair(xb, yb)] = n;
        n++;
        g.resize(n);
      }
      int A = mp[make_pair(xa, ya)];
      int B = mp[make_pair(xb, yb)];
      g[A].emplace_back(B, i);
      g[B].emplace_back(A, i);
    }
    auto signum = [&](long long z) {
      return (z > 0 ? 1 : (z < 0 ? -1 : 0));
    };
    for (int i = 0; i < n; i++) {
      if ((int) g[i].size() > 2) {
        sort(g[i].begin() + 1, g[i].end(), [&](pair<int,int> p1p, pair<int,int> p2p) {
          int p1 = p1p.first;
          int p2 = p2p.first;
          long long xx0 = x[g[i][0].first] - x[i];
          long long yy0 = y[g[i][0].first] - y[i];
          long long xx1 = x[p1] - x[i];
          long long yy1 = y[p1] - y[i];
          long long xx2 = x[p2] - x[i];
          long long yy2 = y[p2] - y[i];
          long long vmul1 = signum(xx0 * yy1 - yy0 * xx1);
          long long vmul2 = signum(xx0 * yy2 - yy0 * xx2);
          if (vmul1 != vmul2) {
            return vmul1 < vmul2;
          }
          long long vmul3 = signum(xx1 * yy2 - xx2 * yy1);
          return vmul3 > 0;
        });
      }
    }
    vector<int> was(n, 0);
    vector<int> res;
    vector<int> depth(n);
    function<void(int,int)> dfs = [&](int v, int pr) {
      was[v] = 1;
      int pos = 0;
      for (int j = 0; j < (int) g[v].size(); j++) {
        int to = g[v][j].first;
        if (to == pr) {
          pos = j;
          break;
        }
      }
      for (int j = (pos + 1) % (int) g[v].size(); ; j = (j + 1) % (int) g[v].size()) {
        int to = g[v][j].first;
        int id = g[v][j].second;
        if (!was[to]) {
          depth[to] = depth[v] + 1;
          dfs(to, v);
        }
        if (depth[to] > depth[v]) {
          res.push_back(id);
        }
        if (j == pos) {
          break;
        }
      }
    };
    for (int i = 0; i < n; i++) {
      if (was[i]) {
        continue;
      }
      dfs(i, -1);
    }
    if (k == 2) {
      int pos1 = -1, pos2 = -1;
      for (int i = 0; i < m; i++) {
        if (res[i] == 0) pos1 = i;
        if (res[i] == 1) pos2 = i;
      }
      if (pos1 > pos2) {
        reverse(res.begin(), res.end());
      }
    }
    for (int i = 0; i < m; i++) {
      if (i > 0) cout << " ";
      cout << res[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}
