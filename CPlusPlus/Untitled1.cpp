#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 17;
int n, h[maxn], over[maxn];
vector<pair<int, int>> g[maxn];
struct Data{
	ll mx;
	int cnt;
	Data(ll mx = 0, int cnt = 0) : mx(mx), cnt(cnt){}
	Data &operator =(int x){
		mx = x, cnt = 1;
		return *this;
	}
};
Data *prefs[maxn], down[maxn], up[maxn];
Data operator +(Data a, Data b){
	if(a.mx > b.mx)
		return a;
	if(a.mx < b.mx)
		return b;
	return Data(a.mx, a.cnt + b.cnt);
}
void dfsd(int v = 0, int p = -1){
	for(int i = 0; i < g[v].size(); i++){
		int u = g[v][i].first;
		if(u != p){
			h[u] = h[v] + 1;
			dfsd(u, v);
		}
		else{
			swap(g[v][i], g[v].back());
			g[v].pop_back();
			i--;
		}	
	}
	Data *pref = prefs[v] = new Data[ g[v].size() + 1];
	pref[0] = {0, 1};
	for(int i = 0; i < g[v].size(); i++){
		int u = g[v][i].first, w = g[v][i].second;
		pref[i + 1] = pref[i] + Data(down[u].mx + w, down[u].cnt);
	}
	down[v] = pref[ g[v].size() ];
}
void dfsu(int v = 0, int overHead = 0){
	Data *pref = prefs[v];
	over[v] = overHead;
	Data curSuf({});
	for(int i = (int) g[v].size() - 1; i >= 0; i--){
		int u = g[v][i].first, w = g[v][i].second;
		up[u] = Data(up[v].mx + overHead, up[v].cnt) + curSuf + pref[i];
		curSuf = curSuf + Data(down[u].mx + w, down[u].cnt);
		dfsu(u, w);
	}
}
pair<int, int> e[maxn];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int v, u, w;
		cin >> v >> u >> w;
		v--, u--;
		g[v].push_back({u, w});
		g[u].push_back({v, w});
		e[i] = {v, u};
	}
	dfsd();
	up[0] = {-1};
	dfsu();
	ll dia = 0;
	for(int i = 1; i < n; i++)
		if(dia < up[i].mx + over[i] + down[i].mx)
			dia = up[i].mx + over[i] + down[i].mx;
	for(int i = 1; i < n; i++){
		auto v = e[i].first, u = e[i].second;
		if(h[v] > h[u])
			swap(v, u);
		if(down[u].mx + over[u] + up[u].mx == dia)
			cout << (ll) down[u].cnt * up[u].cnt << ' ';
		else
			cout << "0 ";
	}
	cout << '\n';
}
