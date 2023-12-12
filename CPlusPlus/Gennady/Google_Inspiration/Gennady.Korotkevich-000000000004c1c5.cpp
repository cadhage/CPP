/**
 *    author:  tourist
 *    created: 09.06.2018 17:13:45       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  srand((int) time(0));
  for (int qq = 1; qq <= tt; qq++) {
    int FROM, TO;
    scanf("%d %d", &FROM, &TO);
    int n = FROM + rand() % (TO - FROM + 1);
    {
      vector<vector<int>> mat(n, vector<int>(n, 0));
      auto add = [&](int x, int y) {
        mat[x][y] = mat[y][x] = 1;
      };
      for (int i = 0; i < n - 1; i++) {
        if (i != 0) {
          add(i, (i + 1) % (n - 1));
        }
      }
      for (int i = 0; i < n - 1; i++) {
        if (i != 3) {
          add(i, (i + 2) % (n - 1));
        }
      }
      add(0, n - 1);
      add(1, n - 1);
      add(3, n - 1);
      add(5, n - 1);
      vector<vector<int>> cc(n, vector<int>(n, 0));
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          for (int k = j + 1; k < n; k++) {
            if (mat[i][j] + mat[i][k] + mat[j][k] == 3) {
              cc[i][j]++;
              cc[i][k]++;
              cc[j][k]++;
              cc[j][i]++;
              cc[k][i]++;
              cc[k][j]++;
            }
          }
        }
      }
      printf("%d\n", n);
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (mat[i][j]) {
            printf("%d %d\n", i + 1, j + 1);
          }
        }
      }
      fflush(stdout);
    }
    {
      vector<vector<int>> mat(n, vector<int>(n, 0));
      int foo;
      scanf("%d", &foo);
      assert(n == foo);
      for (int i = 0; i < 2 * n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        mat[x][y] = mat[y][x] = 1;
      }
      vector<vector<int>> cc(n, vector<int>(n, 0));
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          for (int k = j + 1; k < n; k++) {
            if (mat[i][j] + mat[i][k] + mat[j][k] == 3) {
              cc[i][j]++;
              cc[i][k]++;
              cc[j][k]++;
              cc[j][i]++;
              cc[k][i]++;
              cc[k][j]++;
            }
          }
        }
      }
      vector<vector<int>> zeros(n), twos(n);
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (cc[i][j] == 2) {
            twos[i].push_back(j);
            twos[j].push_back(i);
          }
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (mat[i][j] && cc[i][j] == 0) {
            zeros[i].push_back(j);
            zeros[j].push_back(i);
          }
        }
      }
      vector<int> starts;
      for (int i = 0; i < n; i++) {
        if (twos[i].size() == 2) {
          if (twos[twos[i][0]].size() == 1 && twos[twos[i][1]].size() == 1) {
            starts.push_back(i);
          }
        }
      }
      assert(starts.size() == 1);
      int p = starts[0];
      vector<int> was(n, 0);
      vector<int> quality;
      vector<int> order;
      while (true) {
        order.push_back(p);
        was[p] = 1;
        int found = 0;
        for (int i : twos[p]) {
          if (!was[i]) {
            p = i;
            found = 1;
            quality.push_back(2);
            break;
          }
        }
        if (!found) {
          for (int i : zeros[p]) {
            if (!was[i]) {
              p = i;
              found = 1;
              quality.push_back(0);
              break;
            }
          }
          if (!found) {
            break;
          }
        }
      }
      assert((int) order.size() == n - 1);
      if (quality[2] == 2) {
        reverse(order.begin() + 1, order.end());
      }
      for (int i = 0; i < n; i++) {
        if (!was[i]) {
          order.push_back(i);
        }
      }
      vector<int> match;
      match.push_back(3);
      match.push_back(2);
      match.push_back(0);
      match.push_back(n - 1);
      for (int i = 5; i <= n - 2; i++) {
        match.push_back(i);
      }
      match.push_back(1);
      match.push_back(4);
      assert((int) match.size() == n);
      vector<int> ret(n);
      for (int i = 0; i < n; i++) {
        ret[match[i]] = order[i];
      }
      for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", ret[i] + 1);
      }
      printf("\n");
      fflush(stdout);
    }
  }
  return 0;
}
