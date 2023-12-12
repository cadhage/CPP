#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		long long n;cin>>n;
		vector<long long> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		long long ans=0;
		for(int rot=0;rot<2;rot++){		
			int y,m,d;cin>>y>>m>>d;
			long long cur=0;
			int total=accumulate(a.begin(),a.end(),0);
			cur+=(long long)total*(y-1);
			cur+=(y-1)/4;
			for(int i=0;i<m-1;i++)
				cur+=a[i];
			cur+=d;
			ans+=(rot==1?cur:-cur);
			}
			cout<<ans+1<<'\n';
		}
		return 0;
}
