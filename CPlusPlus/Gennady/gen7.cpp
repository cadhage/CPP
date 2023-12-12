#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		long long n,q;cin>>n>>q;
		vector<int> a(n);
		vector<int> b(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		map<int,vector<int>> mb;
		for(int i=0;i<n;i++)
			mb[b[i]].push_back(i);
		set<tuple<int,int,int>> s;
		int ans=0;
		for(int i=0;i<n;i++){
			ans+=a[i]==b[i];
			s.emplace(i,i,a[i]);
		}
		auto eval=[&](int from,int to ,int val){
			if(mb.find(val)==mb.end()){
				return 0;
			}
			int res=(int)(lower_bound(mb[val].begin(),mb[val].end(),to+1)-
				lower_bound(mb[val].begin(),mb[val].end(),from));
			return res;
		};
		
		while(q--){
			int x,y,z;
			cin>>x>>y>>z;
			x^=ans;
			y^=ans;
			z^=ans;
			assert(1<=x&& x<=y && y<=n);
			x--;y--;
			for(int pos:{x,y+1}){
				if(pos==n)
					continue;
			auto it=s.lower_bound(make_tuple(pos,-1,-1));
			if(it==s.end()|| get<0>(*it)!=pos){
				it--;
				auto p=*it;
				s.erase(it);
				s.insert(make_tuple(get<0>(p),pos-1,get<2>(p)));
				s.insert(make_tuple(pos,get<1>(p),get<2>(p)));
			}
		}
		auto it=s.lower_bound(make_tuple(x,-1,-1));
		while(it!=s.end()&& get<0>(*it)<=y){
			ans-=eval(get<0>(*it),get<1>(*it),get<2>(*it));
			it=s.erase(it);
		}
		ans+=eval(x,y,z);
		s.emplace(x,y,z);
		cout<<ans<<'\n';
	}}
	return 0;
}
