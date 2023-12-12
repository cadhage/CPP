/**
 *    author:  tourist
 *    created: 16.05.2020 17:30:14       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ":";
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 1; i < n; i++) {
      cin >> x[i];
    }
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; i++) {
      cin >> e[i].first >> e[i].second;
      --e[i].first;
      --e[i].second;
    }
    for (int val = 1; val <= n; val++) {
      vector<int> pos;
      for (int i = 0; i < n; i++) {
        if (x[i] >= 0) {
          pos.push_back(x[i]);
        }
      }
      sort(pos.begin(), pos.end());
      assert((int) pos.size() >= val);
      for (int i = 0; i < n; i++) {
        if (x[i] == -val) {
          x[i] = pos[val - 1] + 1;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      int d = max(1, abs(x[e[i].first] - x[e[i].second]));
      cout << " " << d;
    }
    cout << '\n';
  }
  return 0;
}
