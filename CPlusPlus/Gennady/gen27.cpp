#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n,m;cin>>n>>m;
		vector<int> loses(n,-1);
		for(int i=0;i<m;i++){
			int x,y;cin>>x>>y;
			x--;y--;
			if(loses[y]!=-1){
				loses[y]=-2;
			}else{
				loses[y]=x;
			}
		}
		for(int i=0;i<n;i++){
			if(loses[i]>=0 && loses[loses[i]]!=-1){
				loses[i]=-2;
			}
		}
		vector<int> cc(n,0);
		for(int i=0;i<n;i++){
			if(loses[i]>=0){
				cc[loses[i]]++;
			}
		}
		debug(loses,cc);
		multiset<int> s;
		for(int i=0;i<n;i++){
			if(loses[i]==-1){
				s.insert(cc[i]);
			}
		}
		int ans=0;
		while(s.size()>1){
			int x=*s.begin();
			s.erase(s.begin());
			int y=*s.begin();
			s.erase(s.begin());
			s.insert(max(x,y)+1);
			ans++;
		}
		ans+=*s.begin()-1;
		cout<<ans<<'\n';
	}
	return 0;
}
