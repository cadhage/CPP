/**
 *    author:  tourist
 *    created: 31.03.2018 11:41:48       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = 502;
  const int inf = (int) 1e9;
  const int MAGIC = 100;
  vector< vector<int> > dp(MAX, vector<int>(MAX, -inf));
  dp[0][0] = 0;
  for (int x = 0; x <= MAGIC; x++) {
    for (int y = 0; y <= MAGIC; y++) {
      if (x + y == 0) {
        continue;
      }
      for (int i = MAX - 1 - x; i >= 0; i--) {
        for (int j = MAX - 1 - y; j >= 0; j--) {
          dp[i + x][j + y] = max(dp[i + x][j + y], dp[i][j] + 1);
        }
      }
    }
  }
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int r, b;
    cin >> r >> b;
    cout << dp[r][b] << '\n';
  }
  return 0;
}
