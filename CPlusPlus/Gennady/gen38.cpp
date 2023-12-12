#include <bits/stdc++.h>

using namespace std;
string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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
template <typename T>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
  };

  vector<edge> edges;
  vector<vector<int>> g;
  int n;

  graph(int _n) : n(_n) {
    g.resize(n);
  }

  virtual int add(int from, int to, T cost) = 0;
};
template<typename T>
class forest:public graph<T>{
	public:
		using graph<T>::edges;
		using graph<T>::g;
		using graph<T>::n;
		forest(int _n):graph<T>(_n){
			
		}
		int add(int from,int to,T cost=1){
			assert(0<=from &&from<n&&0<=to&&to<n);
			int id=(int)edges.size();
			assert(id<n-1);
			g[from].push_back(id);
			g[to].push_back(id);
			edges.push_back({from,to,cost});
			return id;
		}
};
template<typename T>
class dfs_forest:public forest<T>{
	public:
		using forest<T>::edges;
		using forest<T>::g;
		using forest<T>::n;
		vector<int> pv;
		vector<int> pe;
		vector<int> order;
		vector<int> pos;
		vector<int> end;
		vector<int> sz;
		vector<int> root;
		vector<int> depth;
		vector<T> dist;
		dfs_forest(int _n):forest<T>(_n){
		}
		void init(){
			pv=vector<int> (n,-1);
			pe=vector<int> (n,-1);
			order.clear();
			pos=vector<int> (n,-1);
			end=vector<int> (n,-1);
			sz=vector<int>(n,0);
			root=vector<int>(n,-1);
			depth=vector<int>(n,-1);
			dist=vector<T>(n);
		}
		void clear(){
			pv.clear();
			pe.clear();
			order.clear();
			pos.clear();
			end.clear();
			sz.clear();
			root.clear();
			depth.clear();
			dist.clear();
		}
		private:
			void do_dfs(int v){
				pos[v]=(int)order.size();
				order.push_back(v);
				sz[v]=1;
				for(int id:g[v]){
					if(id==pe[v]){
						continue;
					}
					auto &e=edges[id];
					int to=e.from^e.to^v;
					depth[to]=depth[v]+1;
					dist[to]=dist[v]+e.cost;
					pv[to]=v;
					pe[to]=id;
					root[to]=(root[v]!=-1?root[v]:to);
					do_dfs(to);
					sz[v]+=(int)order.size()-1;
				}
				end[v]=(int)order.size()-1;
			}
			void do_dfs_from(int v){
				depth[v]=0;
				dist[v]=T{};
				root[v]=v;
				pv[v]=pe[v]=-1;
				do_dfs(v);
			}
			public:
				void dfs(int v,bool clear_order=true){
					if(pv.empty()){
						init();
					}else{
						if(clear_order){
							order.clear();
						}
					}
					do_dfs_from(v);
				}
				void dfs_all(){
					init();
					for(int v=0;v<n;v++){
						if(depth[v]==-1){
							do_dfs_from(v);
						}
					}
					assert((int)order.size()==n);
				}
};
template <typename T>
class lca_forest : public dfs_forest<T> {
 public:
  using dfs_forest<T>::edges;
  using dfs_forest<T>::g;
  using dfs_forest<T>::n;
  using dfs_forest<T>::pv;
  using dfs_forest<T>::pos;
  using dfs_forest<T>::end;
  using dfs_forest<T>::depth;

  int h;
  vector<vector<int>> pr;

  lca_forest(int _n) : dfs_forest<T>(_n) {
  }

  inline void build_lca() {
    assert(!pv.empty());
    int max_depth = 0;
    for (int i = 0; i < n; i++) {
      max_depth = max(max_depth, depth[i]);
    }
    h = 1;
    while ((1 << h) <= max_depth) {
      h++;
    }
    pr.resize(n);
    for (int i = 0; i < n; i++) {
      pr[i].resize(h);
      pr[i][0] = pv[i];
    }
    for (int j = 1; j < h; j++) {
      for (int i = 0; i < n; i++) {
        pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
      }
    }
  }

  inline bool anc(int x, int y) {
    return (pos[x] <= pos[y] && end[y] <= end[x]);
  }

  inline int go_up(int x, int up) {
    assert(!pr.empty());
    up = min(up, (1 << h) - 1);
    for (int j = h - 1; j >= 0; j--) {
      if (up & (1 << j)) {
        x = pr[x][j];
        if (x == -1) {
          break;
        }
      }
    }
    return x;
  }

  inline int lca(int x, int y) {
    assert(!pr.empty());
    if (anc(x, y)) {
      return x;
    }
    if (anc(y, x)) {
      return y;
    }
    for (int j = h - 1; j >= 0; j--) {
      if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
        x = pr[x][j];
      }
    }
    return pr[x][0];
  }
};

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<int> s(n);
	for(int i=0;i<n;i++){
		cin>>s[n];
	}
	lca_forest<int> g(n);
	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		g.add(x,y);
	}
	g.dfs(0);
	g.build_lca();
	int tt;
	cin>>tt;
	vector<int> u(tt);
	vector<int> v(tt);
	vector<int> x(tt);
	vector<int> w(tt);
	for(int i=0;i<tt;i++){
		cin>>u[i]>>v[i]>>x[i];
		u[i]--;v[i]--;
		w[i]=g.lca(u[i],v[i]);
	}
	vector<long long> res(tt,0);
	const int inf=(int)1e5+1;
	vector<int> low(tt,0);
	vector<int> high(tt,inf);
	vector<int> mid(tt);
	while(true){
		bool any=false;
		for(int i=0;i<tt;i++){
			mid[i]=(low[i]+high[i]+1);
			any|=(low[i]<high[i]);
		}
		if(!any){
			break;
		}
		vector<pair<int,int>> e;
		for(int i=0;i<tt;i++){
			if(low[i]<high[i]){
				e.emplace_back(mid[i],i);
			}
		}
		for(int i=0;i<n;i++){
			e.emplace_back(s[i],~i);
		}
		sort(e.begin(),e.end());
		fenwick<long long> fenw(n);
		for(auto &p:e){
			int id=p.second;
			if(id>=0){
				long long sum=fenw.get(g.pos[u[id]]);
				sum+=fenw.get(g.pos[v[id]]);
				sum+=fenw.get(g.pos[w[id]]);
				if(g.pv[w[id]]!=-1){
					sum-=fenw.get(g.pos[g.pv[w[id]]]);
				}
				if(((sum)>>20)<=x[id]){
					res[id]=sum;
					low[id]=mid[id];
					
				}
				else{
					high[id]=mid[id]-1;
				}
			}
			else{
				id=~id;
				fenw.modify(g.pos[id],((long long)s[id]<<20)+1);
				fenw.modify(g.end[id]+1,-((((long long)s[id])<<20)+1));
			}
		}
	}
	for(int i=0;i<tt;i++){
		long long sum=res[i]>>20;
		int ans=(int)(res[i]&((1<<20)-1));
		if(low[i]<inf){
			ans+=(int)((x[i]-sum)/(low[i]+1));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
