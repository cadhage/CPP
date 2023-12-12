#include <bits/stdc++.h>
using namespace std;
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
	T get(int x){
		T v{};
		while(x>=0){
			v+=fenw[x];
			x=(x&(x+1))-1;
		}
		return v;
	}
};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n,k;cin>>n>>k;
		vector<int> a(n);
		int ok=1;
		for(int i=0;i<n;i++){
			cin>>a[i];
			--a[i];
			if(a[i]%k!=i%k){
				ok=0;
			}
		}
		if(!ok){
			cout<<-1<<'\n';
			continue;
		}
		long long ans=0;
		for(int r=0;r<min(k,n);r++){
			int cc=0;
			for(int i=0;i*k+r<n;i++){
				cc++;
			}
			vector<int> pos(cc);
			for(int i=0;i*k+r<n;i++){
				pos[a[i*k+r]/k]=i;
			}
			fenwick<int> fenw(cc);
			for(int i=(int)pos.size()-1;i>=0;i--){
				ans+=fenw.get(pos[i]);
				fenw.modify(pos[i],1);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
