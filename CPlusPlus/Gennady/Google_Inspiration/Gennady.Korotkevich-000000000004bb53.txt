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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    int dx = *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end());
    int dy = *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end());
    int d = max(dx, dy);
    cout << (d + 1) / 2 << '\n';
  }
  return 0;
}
