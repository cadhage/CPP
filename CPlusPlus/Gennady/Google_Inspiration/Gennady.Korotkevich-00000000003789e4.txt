/**
 *    author:  tourist
 *    created: 06.06.2020 18:20:12       
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n, d;
    cin >> n >> d;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) {
      long long foo, bar;
      cin >> foo >> bar;
      x[i] = foo - bar;
      y[i] = foo + bar;
    }
    vector<long long> xs;
    vector<long long> ys;
    for (int i = 0; i < n; i++) {
      xs.push_back(x[i] - d);
      xs.push_back(x[i] + d);
      ys.push_back(y[i] - d);
      ys.push_back(y[i] + d);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
    map<vector<pair<long long, long long>>, vector<tuple<long long, long long, long long, long long>>> mp;
    for (int xi = 0; xi < (int) xs.size() - 1; xi++) {
      for (int yi = 0; yi < (int) ys.size() - 1; yi++) {
        long long xa = xs[xi];
        long long xb = xs[xi + 1];
        long long ya = ys[yi];
        long long yb = ys[yi + 1];
        vector<pair<long long, long long>> pts;
        for (int i = 0; i < n; i++) {
          if (x[i] - d <= xa && xb <= x[i] + d && y[i] - d <= ya && yb <= y[i] + d) {
            pts.emplace_back(x[i], y[i]);
          }
        }
        if (pts.empty()) {
          continue;
        }
        sort(pts.begin(), pts.end());
        xa -= pts[0].first;
        xb -= pts[0].first;
        ya -= pts[0].second;
        yb -= pts[0].second;
        for (int i = (int) pts.size() - 1; i >= 0; i--) {
          pts[i].first -= pts[0].first;
          pts[i].second -= pts[0].second;
        }
        mp[pts].emplace_back(xa, ya, xb, yb);
      }
    }
//    debug(mp);
    unsigned long long good = 0;
    unsigned long long bad = 0;
    for (auto& state : mp) {
      xs.clear();
      ys.clear();
      for (auto& p : state.second) {
        xs.push_back(get<0>(p));
        ys.push_back(get<1>(p));
        xs.push_back(get<2>(p));
        ys.push_back(get<3>(p));
      }
      sort(xs.begin(), xs.end());
      sort(ys.begin(), ys.end());
      xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
      ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
      for (int xi = 0; xi < (int) xs.size() - 1; xi++) {
        for (int yi = 0; yi < (int) ys.size() - 1; yi++) {
          long long xa = xs[xi];
          long long xb = xs[xi + 1];
          long long ya = ys[yi];
          long long yb = ys[yi + 1];
          int cnt = 0;
          for (auto& p : state.second) {
            if (get<0>(p) <= xa && xb <= get<2>(p) && get<1>(p) <= ya && yb <= get<3>(p)) {
              cnt += 1;
            }
          }
          if (cnt == 1) {
            good += (unsigned long long) (xb - xa) * (yb - ya);
          }
          if (cnt > 1) {
            bad += (unsigned long long) (xb - xa) * (yb - ya) * cnt;
          }
        }
      }
    }
    unsigned long long ga = good, gb = bad;
    while (ga > 0 && gb > 0) {
      if (ga > gb) ga %= gb;
      else gb %= ga;
    }
    good /= ga + gb;
    bad /= ga + gb;
    cout << good << " " << good + bad << '\n';
  }
  return 0;
}
