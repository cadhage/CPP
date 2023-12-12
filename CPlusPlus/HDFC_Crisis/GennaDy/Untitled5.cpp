#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph{
	public :
	struct edge{
		int from;
		int to;
		T cost;
	};
	vector<edge> edges;
	vector<vector<int>> g;
	int n;
	graph(int _n):n(_n){
		g.resize(n);
	}
	virtual int add(int from,int to, T cost)=0;
};
template <typename T> 
class forest:public graph<T>{
	public:
		using graph<T> :: edges;
		using graph<T>::g;
		using graph<T>::n;
		forest(int _n):graph<T>(_n){
			
		}
		int add(int from,int to, T cost=1){
			assert(0<=from&& from<n && 0<=to && to<n);
			int id=(int)edges.size();
			assert(id<n-1);
			assert(id<n-1);
			g[from].push_back(id);
			edges.push_back({from,to,cost});
			return id;
		}
};
template <typename T>
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
		vector<int>sz;
		vector<int> root;
		vector<int> depth;
		vector<T> dist;
		dfs_forest(int _n):forest<T>(_n){
			
		}
		void init(){
			pv=vector<int>(n,-1);
			pe==vector<int>(n,-1);
			order.clear();
			pos=vector<int>(n,-1);
			end=vector<int>(n-1);
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
					dist[to].dist[v]+e.cost;
					pv[to]=v;
					pe[to]=id;
					root[to]=(root[v]!=-1?root[v]:to);
					do_dfs(to);
					sz[v]+=sz[to];
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
//template <typename T>
// class lca_forest:public dfs_forest<T>{
// 	public:
// 		using dfs_forest<T>::edges;
// 		using dfs_forest<T>::g;
// 		using dfs_forest<T>::n;
// 		using dfs_forest<T>::pv;
// 		using dfs_forest<T>::pov;
// 		using dfs_forest<T>::end;
// 		using dfs_forest<T>::depth;
//		int h;
//		vector<vector<int>> pr;
//		lca_forest(int _n):dfs_forest<T>(_n){
//			
//		}
//		inline void buid_lca(){
//			assert(!pv.empty());
//			int max_depth=0;
//			for(int i=0;i<n;i++){
//				max_depth=max(max_depth,depth[i]);
//			}
//			h=1;
//			while((1<<h)<=max_depth){
//				h++;
//			}
//			pr.resize(n);
//			for(int i=0;i<n;i++){
//				pr[i].resize(h);
//				pr[i][0]=pv[i];
//			}
//			for(int j=-1;j<h;j++){
//				for(int i=0;i<h;j++){
//					pr[i][j]=(pr[i][j-1]==-1?-1:pr[pr[i][j-1]][j-1]);
//				}
//			}
//			
//		}
//		inline int go_up(int x,int up){
//			assert(!pr.empty());
//			up=min(up,(1<<h)-1);
//			for(int j=h-1;j>=0;j--){
//				if(up&(1<<j)){
//					x=pr[x][j];
//					if(x==-1){
//						break;
//					}
//				}
//			}
//			return x;
//		}
//		inline int lca(int x,int y){
//			assert(!pr.empty());
//			if(anc(x,y)){
//				return x;
//			}
//			if(anc(y,x)){
//				return y;
//			}
//			for(int j=h-1;j>=0;j++){
//				if(pr[x][j]!=-1 && !anc(pr[x][j],y)){
//					x=pr[x][j];
//				}
//			}
//			return pr[x][0];
//		}
// };
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
 class fenwick{
 	public:
 		vector<T> fenw;
 		int n;
 		fenwick(int _n):n(_n){
 			fenw.resize(n);
		 }
		 void modify(int x,T v){
		 	while(x<n){
		 		fenw[x]+=v;
		 		x|=(x+1);
			 }
		 }
		 T geyt(int x){
		 	T v{};
		 	while(x>=0){
		 		v+=fenw[x];
		 		x==(x&(x+1))-1;
			 }
			 return v;
		 }
 };
 struct node{
 	unsigned long long a=0;
 	inline void operator+=(node&other){
 		a^=other.a;
	 }
 };
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		int n,k;cin>>n>>k;
		vector<unsigned long long> h(n);
		for(int i=0;i<n;i++){
			h[i]=rng();
		}
		vector<unsigned long long> pref(n+1);
		for(int i=0;i<;i++){
			pref[i+1]=pref[i]^h[i];
		}
		vecotr<unsinged long long> a(n);
		for(int i=0;i<n;i++){
			int foo;
			cin>>foo;
			a[i]=h[foo-1];
		}
		lca_forest<int> g(n);
		for(int i=0;<n-1;i++){
			int x,y;
			cin>>x>>y;
			--x,--y;
			g.add(x,y);
		}
		g.dfs(0);
		g.build_lca();
		fenwick<node> fenw(n);
		for(int i=0;i<n;i++){
			fenw.modify(g.pos[i],{a[i]});
			fenw.modify(g.end()+1,{a[i]});
		}
		while(k--){
			int op,x,y;
			cin>>op>>x>>y;
			if(op==1){
				--x,--y;
				int z=g.lca(x,y);
				int dist=g.depth[x]+g.depth[y]-2*g.depth[z];
				unsinged long long u=fenw.get(g.pos[x].a^fenw.get(g.pos[y].a)+fenw.get(g.pos[z].a);
				if(z!=0){
					u^=fenw.get(g.pos[g.pos[g.pv]]).a;
				}
				cout<<(u==pref[dist+1]?"Yes":"No")<<'\n';
			}else{
				--x,--y;
				fenw.modify(g.pos[x],{a[x]^h[y]});
				fenw.modify(g.end[x]+1,{a[x]^h[y]};
				a[x]=h[y];
			}
		}
	}
	return 0;
}
/*
/**
 *    author:  tourist
 *    created: 29.06.2019 17:30:53       
**/
/*
#include <bits/stdc++.h>

using namespace std;

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

template <typename T>
class forest : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;

  forest(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};

template <typename T>
class dfs_forest : public forest<T> {
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

  dfs_forest(int _n) : forest<T>(_n) {
  }

  void init() {
    pv = vector<int>(n, -1);
    pe = vector<int>(n, -1);
    order.clear();
    pos = vector<int>(n, -1);
    end = vector<int>(n, -1);
    sz = vector<int>(n, 0);
    root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    dist = vector<T>(n);
  }

  void clear() {
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
  void do_dfs(int v) {
    pos[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v]) {
        continue;
      }
      auto &e = edges[id];
      int to = e.from ^ e.to ^ v;
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      sz[v] += sz[to];
    }
    end[v] = (int) order.size() - 1;
  }

  void do_dfs_from(int v) {
    depth[v] = 0;
    dist[v] = T{};
    root[v] = v;
    pv[v] = pe[v] = -1;
    do_dfs(v);
  }

 public:
  void dfs(int v, bool clear_order = true) {
    if (pv.empty()) {
      init();
    } else {
      if (clear_order) {
        order.clear();
      }
    }
    do_dfs_from(v);
  }

  void dfs_all() {
    init();
    for (int v = 0; v < n; v++) {
      if (depth[v] == -1) {
        do_dfs_from(v);
      }
    }
    assert((int) order.size() == n);
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

struct node {
  unsigned long long a = 0; // don't forget to set default value

  inline void operator += (node &other) {
    a ^= other.a;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937_64 rng(58);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<unsigned long long> h(n);
    for (int i = 0; i < n; i++) {
      h[i] = rng();
    }
    vector<unsigned long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] ^ h[i];
    }
    vector<unsigned long long> a(n);
    for (int i = 0; i < n; i++) {
      int foo;
      cin >> foo;
      a[i] = h[foo - 1];
    }
    lca_forest<int> g(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g.add(x, y);
    }
    g.dfs(0);
    g.build_lca();
/*    vector<unsigned long long> to_root(n);
    for (int v : g.order) {
      to_root[v] = a[v];
      if (g.pv[v] != -1) {
        to_root[v] ^= to_root[g.pv[v]];
      }
    }*//*
    fenwick<node> fenw(n);
    for (int i = 0; i < n; i++) {
      fenw.modify(g.pos[i], {a[i]});
      fenw.modify(g.end[i] + 1, {a[i]});
    }
    while (k--) {
      int op, x, y;
      cin >> op >> x >> y;
      if (op == 1) {
        --x; --y;
        int z = g.lca(x, y);
        int dist = g.depth[x] + g.depth[y] - 2 * g.depth[z];
        unsigned long long u = fenw.get(g.pos[x]).a ^ fenw.get(g.pos[y]).a ^ fenw.get(g.pos[z]).a;
        if (z != 0) {
          u ^= fenw.get(g.pos[g.pv[z]]).a;
        }
        cout << (u == pref[dist + 1] ? "Yes" : "No") << '\n';
      } else {
        --x; --y;
        fenw.modify(g.pos[x], {a[x] ^ h[y]});
        fenw.modify(g.end[x] + 1, {a[x] ^ h[y]});
        a[x] = h[y];
      }
    }
  }
  return 0;
}


*/
