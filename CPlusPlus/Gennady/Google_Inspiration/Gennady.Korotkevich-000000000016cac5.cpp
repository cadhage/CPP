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

const int DX[4] = {-1, 0, 1, 0};
const int DY[4] = {0, -1, 0, 1};

const int MAX = 40010;

int qx[MAX];
int qy[MAX];

void RunBfs(const vector<string>& s, int sx, int sy, vector<vector<int>>& dist) {
  int h = (int) s.size();
  int w = (int) s[0].size();
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      dist[i][j] = -1;
    }
  }
  if (s[sx][sy] == '#') {
    return;
  }
  int b = 0, e = 1;
  qx[0] = sx;
  qy[0] = sy;
  dist[sx][sy] = 0;
  while (b < e) {
    for (int dir = 0; dir < 4; dir++) {
      int nx = qx[b] + DX[dir];
      int ny = qy[b] + DY[dir];
      if (nx >= 0 && ny >= 0 && nx < h && ny < w) {
        if (s[nx][ny] != '#' && dist[nx][ny] == -1) {
          qx[e] = nx;
          qy[e] = ny;
          dist[nx][ny] = dist[qx[b]][qy[b]] + 1;
          ++e;
        }
      }
    }
    ++b;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(17);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
      cin >> s[i];
    }
    int sx = -1, sy = -1;
    int fx = -1, fy = -1;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (s[i][j] == 'M') {
          sx = i;
          sy = j;
        }
        if (s[i][j] == 'N') {
          fx = i;
          fy = j;
        }
      }
    }
    vector<vector<int>> dist(h, vector<int>(w));
    RunBfs(s, sx, sy, dist);
    vector<vector<int>> dist_start = dist;
    if (dist[fx][fy] == -1) {
      cout << "IMPOSSIBLE" << '\n';
      continue;
    }
    int ans = dist[fx][fy];
    RunBfs(s, fx, fy, dist);
    vector<vector<int>> dist_finish = dist;
    for (int dx = -h + 1; dx <= h - 1; dx++) {
      for (int dy = -w + 1; dy <= w - 1; dy++) {
        if (dx == 0 && dy == 0) {
          continue;
        }
        int mx = fx - dx;
        int my = fy - dy;
        if (mx < 0 || my < 0 || mx >= h || my >= w || s[mx][my] == '#') {
          continue;
        }
        RunBfs(s, mx, my, dist);
        vector<vector<int>> dist_old = dist;
        vector<string> g = s;
        for (int cycles = 1; ; cycles++) {
          for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
              if (g[i][j] != '#') {
                int ni = i - dx * cycles;
                int nj = j - dy * cycles;
                if (ni < 0 || nj < 0 || ni >= h || nj >= w || s[ni][nj] == '#') {
                  g[i][j] = '#';
                }
              }
            }
          }
          if (g[fx][fy] == '#') {
            break;
          }
          RunBfs(g, fx, fy, dist);
          for (int zx = 0; zx < h; zx++) {
            for (int zy = 0; zy < w; zy++) {
              if (g[zx][zy] == '#') {
                continue;
              }
              int ux = zx - dx * cycles;
              int uy = zy - dy * cycles;
              assert(ux >= 0 && uy >= 0 && ux < h && uy < w);
              if (dist[zx][zy] == -1 || dist_old[zx][zy] == -1 || dist_start[ux][uy] == -1) {
                continue;
              }
              int cur = dist_start[ux][uy] + dist[zx][zy] + dist_old[zx][zy] + 1;
//              debug(dx, dy, cycles, zx, zy, cur, g, dist_old[zx][zy]);
              ans = min(ans, cur);
            }
          }
          RunBfs(g, mx, my, dist);
          dist_old = dist;
//          debug(dx, dy, cycles, g, mx, my, dist);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
