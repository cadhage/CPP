#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	const int MAX=1000010;
	vector<int> p(MAX);
	for(int i=0;i<MAX;i++)
		p[i]=i;
	for(int i=2;i<MAX;i++){
		if(p[i]==i){
			for(int j=i+i;j<MAX;j+=i){
				if(p[j]==j){
					p[j]=i;
				}
			}
		}
	}
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		vector<vector<int>> cc(MAX);
		for(int i=0;i<n;i++){
			int x;cin>>x;
			while(x>1){
				int r=0;
				int d=p[x];
				while(x%d==0){
					x/=d;
					r++;
				}
				cc[d].push_back(r);
			}
		}
		int ans=1;
		for(int d=2;d<MAX;d++){
			if(cc[d].empty()){
				continue;
			}
			for(int j=20;j>=1;j--){
				int extra=0;
				long long need=0;
				for(int i:cc[d]){
					if(i>=j){
						extra+=(i-j)/2;
						
					}else{
						need+=j-i;
					}
				}
				need+=(long long)j*(n-(int)cc[d].size());
				if(extra>=need){
					for(int k=0;k<j;k++){
						ans*=d;
					}
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
