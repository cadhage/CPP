/**
 *    author:  tourist
 *    created: 06.06.2020 18:53:58       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int Solve(vector<long long> d) {
  int n = (int) d.size();
  if (n % 2 == 1) {
    long long s = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        s += 2 * d[i];
      } else {
        s -= 2 * d[i];
      }
    }
    long long x = s / 2;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (x < 0) {
        ok = false;
        break;
      }
      x = 2 * d[i] - x;
    }
    if (ok) {
      return n;
    }
  }
  vector<vector<long long>> from(n + 1, vector<long long>(n + 1, -1));
  vector<vector<long long>> to(n + 1, vector<long long>(n + 1, -1));
  vector<vector<long long>> diff(n + 1, vector<long long>(n + 1, -1));
  vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, -1));
  int ans = 0;
  for (int shift = 0; shift < n; shift++) {
    // x[0] = x[n] = 0
    d.push_back(0);
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        from[i][j] = to[i][j] = diff[i][j] = -1;
      }
    }
    for (int i = 0; i < n; i++) {
      long long L = 0;
      long long R = d[i];
      if (i == 0) {
        R = 0;
      }
      long long delta = 0;
      for (int j = i; j < n; j++) {
        delta = d[j] - delta;
        if (j % 2 == i % 2) {
          // delta - x >= 0
          R = min(R, delta);
          if (j == n - 1) {
            L = max(L, delta);
          }
        } else {
          // delta + x >= 0
          L = max(L, -delta);
          if (j == n - 1) {
            R = min(R, -delta);
          }
        }
        if (L <= R) {
          from[i][j] = L;
          to[i][j] = R;
          diff[i][j] = delta;
//          debug(d, i, j, L, R, delta);
        }
      }
    }
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= n + 1; j++) {
        dp[i][j] = -1;
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= n + 1; j++) {
        if (dp[i][j] == -1) {
          continue;
        }
        ans = max(ans, j);
        for (int k = i; k < n; k++) {
          if (from[i][k] >= 0) {
            if ((k & 1) == (i & 1)) {
              long long L = from[i][k];
              long long R = to[i][k];
              R = min(R, dp[i][j]);
              if (L <= R) {
                int nj = j + (k - i + 1);
                dp[k + 2][nj] = max(dp[k + 1][nj], d[k + 1] - (diff[i][k] - R));
              }
            } else {
              long long L = from[i][k];
              long long R = to[i][k];
              R = min(R, dp[i][j]);
              if (L <= R) {
                int nj = j + (k - i + 1);
                dp[k + 2][nj] = max(dp[k + 1][nj], d[k + 1] - (diff[i][k] + L));
              }
            }
          }
        }
      }
    }
    d.pop_back();
    rotate(d.begin(), d.begin() + 1, d.end());
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int k, n;
    cin >> k >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
      cin >> t[i];
    }
    vector<long long> d(n);
    for (int i = 0; i < n - 1; i++) {
      d[i] = x[i + 1] - x[i] - 1;
    }
    d[n - 1] = x[0] + k - x[n - 1] - 1;
    cout << 2 * n - Solve(d) << '\n';
  }
  return 0;
}
