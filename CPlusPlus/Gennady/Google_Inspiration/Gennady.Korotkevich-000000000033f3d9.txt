/**
 *    author:  tourist
 *    created: 16.05.2020 18:51:18       
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

const long long inf = (long long) 2e12;

const int N = (int) 2e5 + 10;
const int LOG = 20;

long long d[N][LOG][2][2][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "(" + s + ")";
    n += 2;
    vector<long long> L(n), R(n), T(n);
    L[0] = L[n - 1] = R[0] = R[n - 1] = T[0] = T[n - 1] = inf;
    for (int i = 1; i < n - 1; i++) {
      cin >> L[i];
    }
    for (int i = 1; i < n - 1; i++) {
      cin >> R[i];
    }
    for (int i = 1; i < n - 1; i++) {
      cin >> T[i];
    }
    vector<int> st;
    vector<int> lft;
    vector<int> rgt;
    vector<int> pv;
    vector<vector<int>> g;
    vector<int> depth;
    vector<int> whose(n, -1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        whose[i] = cnt;
        lft.push_back(i);
        rgt.push_back(-1);
        pv.push_back(-1);
        depth.push_back(0);
        g.emplace_back();
        if (!st.empty()) {
          pv[cnt] = st.back();
          depth[cnt] = depth[pv[cnt]] + 1;
          g[st.back()].push_back(cnt);
        }
        st.push_back(cnt);
        cnt += 1;
      } else {
        whose[i] = st.back();
        assert(!st.empty());
        rgt[st.back()] = i;
        st.pop_back();
      }
    }
    debug(lft);
    debug(rgt);
    debug(pv);
    debug(g);
    auto GetDist = [&](int i, int j) {
      int wi = whose[i];
      int wj = whose[j];
      int w = -1;
      if (depth[wi] == depth[wj]) {
        w = pv[wi];
      } else {
        w = (depth[wi] < depth[wj] ? wi : wj);
      }
      int sz = ((int) g[w].size() + 1) * 2;
      int pi = -1;
      int pj = -1;
      if (wi == w) {
        pi = (i == lft[wi] ? 0 : sz - 1);
      } else {
        auto iter = lower_bound(g[w].begin(), g[w].end(), wi);
        assert(iter != g[w].end() && *iter == wi);
        pi = (int) (iter - g[w].begin()) * 2 + (i == lft[wi] ? 1 : 2);
      }
      if (wj == w) {
        pj = (j == lft[wj] ? 0 : sz - 1);
      } else {
        auto jter = lower_bound(g[w].begin(), g[w].end(), wj);
        assert(jter != g[w].end() && *jter == wj);
        pj = (int) (jter - g[w].begin()) * 2 + (j == lft[wj] ? 1 : 2);
      }
      int dist = abs(pi - pj);
      dist = min(dist, sz - dist);
      debug(i, j, dist);
      return dist;
    };
    vector<vector<int>> pr(cnt, vector<int>(LOG, -1));
    for (int i = 1; i < cnt; i++) {
      pr[i][0] = pv[i];
      d[i][0][0][0][0] = GetDist(lft[i], lft[pv[i]]);
      d[i][0][0][0][1] = GetDist(lft[i], rgt[pv[i]]);
      d[i][0][0][1][0] = GetDist(rgt[i], lft[pv[i]]);
      d[i][0][0][1][1] = GetDist(rgt[i], rgt[pv[i]]);
      d[i][0][1][0][0] = GetDist(lft[pv[i]], lft[i]);
      d[i][0][1][0][1] = GetDist(rgt[pv[i]], lft[i]);
      d[i][0][1][1][0] = GetDist(lft[pv[i]], rgt[i]);
      d[i][0][1][1][1] = GetDist(rgt[pv[i]], rgt[i]);
    }
    debug("hi");
    for (int j = 1; j < LOG; j++) {
      for (int i = 0; i < cnt; i++) {
        if (pr[i][j - 1] != -1) {
          pr[i][j] = pr[pr[i][j - 1]][j - 1];
          if (pr[i][j] != -1) {
            for (int dir = 0; dir < 2; dir++) {
              for (int me = 0; me < 2; me++) {
                for (int them = 0; them < 2; them++) {
                  long long cur = inf;
                  for (int mid = 0; mid < 2; mid++) {
                    cur = min(cur, d[i][j - 1][dir][me][mid] + d[pr[i][j - 1]][j - 1][dir][mid][them]);
                  }
                  d[i][j][dir][me][them] = cur;
                }
              }
            }
          }
        }
      }
    }
    debug("hi");
    auto GoUp = [&](int& w, int delta, vector<long long>& dist, int dir) {
      vector<long long> new_dist(2);
      for (int j = LOG - 1; j >= 0; j--) {
        if (delta & (1 << j)) {
          new_dist[0] = new_dist[1] = inf;
          for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
              new_dist[y] = min(new_dist[y], dist[x] + d[w][j][dir][x][y]);
            }
          }
          dist[0] = new_dist[0];
          dist[1] = new_dist[1];
          w = pr[w][j];
        }
      }
    };
    auto Solve = [&](int i, int j) -> long long {
      if (i == j) {
        return 0;
      }
      int wi = whose[i];
      int wj = whose[j];
      debug(i, j, wi, wj);
      if (wi == wj) {
        return 1; // !!!
      }
      vector<long long> di(2, 0);
      di[i == lft[wi] ? 1 : 0] = 1; // !!!
      vector<long long> dj(2, 0);
      dj[j == lft[wj] ? 1 : 0] = 1; // !!!
      if (lft[wi] < lft[wj] && rgt[wj] < rgt[wi]) {
        int delta = depth[wj] - depth[wi] - 1;
        GoUp(wj, delta, dj, 1); 
      } else {
        if (lft[wj] < lft[wi] && rgt[wi] < rgt[wj]) {
          int delta = depth[wi] - depth[wj] - 1;
          GoUp(wi, delta, di, 0);
        } else {
          if (depth[wi] > depth[wj]) {
            int delta = depth[wi] - depth[wj];
            GoUp(wi, delta, di, 0);
          }
          if (depth[wi] < depth[wj]) {
            int delta = depth[wj] - depth[wi];
            GoUp(wj, delta, dj, 1);
          }
          debug(wi, wj, di, dj);
          int zi = wi;
          int zj = wj;
          int delta = 0;
          for (int k = LOG - 1; k >= 0; k--) {
//            debug(zi, zj, pr[zi][k], pr[zj][k]);
            if (pr[zi][k] != pr[zj][k]) {
              zi = pr[zi][k];
              zj = pr[zj][k];
              delta += (1 << k);
            }
          }
          debug(delta);
          GoUp(wi, delta, di, 0);
          GoUp(wj, delta, dj, 1);
        }
      }
      debug(wi, wj, di, dj);
      long long ans = inf;
      ans = min(ans, di[0] + GetDist(lft[wi], lft[wj]) + dj[0]);
      ans = min(ans, di[0] + GetDist(lft[wi], rgt[wj]) + dj[1]);
      ans = min(ans, di[1] + GetDist(rgt[wi], lft[wj]) + dj[0]);
      ans = min(ans, di[1] + GetDist(rgt[wi], rgt[wj]) + dj[1]);
      return ans;
    };
    {
      vector<int> u(q);
      vector<int> v(q);
      for (int i = 0; i < q; i++) {
        cin >> u[i];
      }
      for (int i = 0; i < q; i++) {
        cin >> v[i];
      }
      long long ans = 0;
      for (int i = 0; i < q; i++) {
        long long cur = Solve(u[i], v[i]);
        debug(u[i], v[i], cur);
        ans += cur;
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
