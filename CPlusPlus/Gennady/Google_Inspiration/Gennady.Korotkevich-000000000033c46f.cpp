/**
 *    author:  tourist
 *    created: 16.05.2020 18:13:30       
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
    vector<long long> x(n);
    vector<long long> y(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    int ans = min(n, 2);
    for (int i1 = 0; i1 < n; i1++) {
      for (int i2 = i1 + 1; i2 < n; i2++) {
        long long a = y[i2] - y[i1];
        long long b = x[i1] - x[i2];
        long long c = -a * x[i1] - b * y[i1];
        vector<long long> z(n);
        for (int i = 0; i < n; i++) {
          z[i] = a * x[i] + b * y[i] + c;
        }
        sort(z.begin(), z.end());
        int add = 0;
        int k1 = 0;
        int k3 = 0;
        int beg = 0;
        while (beg < n) {
          int end = beg;
          while (end + 1 < n && z[end + 1] == z[end]) {
            ++end;
          }
          int cnt = end - beg + 1;
          if (cnt % 2 == 0) {
            add += cnt;
          } else {
            if (cnt == 1) {
              k1 += 1;
            } else {
              add += cnt - 3;
              k3 += 1;
            }
          }
          beg = end + 1;
        }
        while (k3 >= 2) {
          add += 6;
          k3 -= 2;
        }
        if (k3 == 0) {
          add += min(k1, 2);
        } else {
          add += 3 + min(k1, 1);
        }
        ans = max(ans, add);
      }
    }
    ans = min(ans, n);
    cout << ans << '\n';
  }
  return 0;
}
