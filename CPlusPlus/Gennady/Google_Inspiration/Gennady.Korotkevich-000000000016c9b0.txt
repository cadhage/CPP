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
  cout << fixed << setprecision(17);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ":" << '\n';
    int p, s, k, n;
    cin >> p >> s >> k >> n;
    vector<vector<int>> tests(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
      vector<pair<int, int>> a(n);
      for (int j = 0; j < n; j++) {
        cin >> a[j].first;
        a[j].second = j;
        tests[i][j] = a[j].first;
      }
      sort(a.begin(), a.end());
      for (int j = 0; j < n; j++) {
//        tests[i][a[j].second] = j;
      }
    }
    vector<int> shifts = {1, min(3, n), min(9, n)};
    vector<int> takes = {1, min(5, n - 1)};
    vector<vector<int>> perm(shifts.size() + takes.size(), vector<int>(n));
    for (int i = 0; i < (int) shifts.size(); i++) {
      for (int j = 0; j < n; j++) {
        perm[i][j] = (j + shifts[i]) % n;
      }
    }
    for (int i = 0; i < (int) takes.size(); i++) {
      int id = (int) shifts.size() + i;
      perm[id][0] = 0;
      for (int j = 1; j < n; j++) {
        perm[id][j] = 1 + ((j - 1 + n - takes[i] - 1) % (n - 1));
      }
    }
    cout << (int) perm.size() << '\n';
    for (int i = 0; i < (int) perm.size(); i++) {
      for (int j = 0; j < n; j++) {
        if (j > 0) {
          cout << " ";
        }
        cout << perm[i][j] + 1;
      }
      cout << '\n';
    }
    for (auto vvv : tests) {
      bool found = false;
      for (int init = 0; init < n; init++) {
        auto v = vvv;
        vector<int> seq;
        auto Apply = [&](int id) {
          seq.push_back(id);
          vector<int> new_v(n);
          for (int i = 0; i < n; i++) {
            new_v[i] = v[perm[id][i]];
          }
          swap(v, new_v);
        };
        auto ManyShifts = [&](int cnt) {
//          debug("shifts", cnt);
          for (int i = (int) shifts.size() - 1; i >= 0; i--) {
            while (cnt >= shifts[i]) {
              Apply(i);
              cnt -= shifts[i];
            }
          }
        };
        auto ManyTakes = [&](int cnt) {
//          debug("takes", cnt);
          for (int i = (int) takes.size() - 1; i >= 0; i--) {
            while (cnt >= takes[i]) {
              Apply((int) shifts.size() + i);
              cnt -= takes[i];
            }
          }
        };
        ManyShifts(init);
        for (int i = 0; i < n; i++) {
          int ptr = n - 1;
          int steps = 0;
          for (int j = 0; j < i; j++) {
            if (v[n - 1 - j] > v[0]) {
              --ptr;
              ++steps;
            } else {
              break;
            }
          }
          ManyTakes(steps);
          ManyShifts(steps + 1);
        }
        for (int i = 0; i < n - 1; i++) {
          assert(v[i] <= v[i + 1]);
        }
        if ((int) seq.size() <= s) {
          cout << seq.size();
          for (int x : seq) {
            cout << " " << x + 1;
          }
          cout << '\n';
          found = true;
          break;
        }
      }
      assert(found);
    }
  }
  return 0;
}
