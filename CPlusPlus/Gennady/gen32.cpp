#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;cin>>n>>m>>k;
	int half=max(k/2,k-8);
	vector<int> cnt(1<<k,0);
	auto add=[&](int x,int cost){
		int x_half=x&((1<<half)-1);
		int x_upper=(x>>half)<<half;
		for(int t=0;t<(1<<half);t++){
			if((x_half&t)==t){
				cnt[x_upper|t]+=cost;
			}
		}	
	};
	for(int i=0;i<n;i++){
		int x;cin>>x;
		add(x,1);
	}
	while(m--){
		int op,v;
		cin>>op>>v;
		if(op==1){
			add(v,1);
		}
		if(op==2){
			add(v,-1);
		}
		if(op==3){
			int x=0;
			for(int bit=k-1;bit>=0;bit--){
				x+=(1<<bit);
				int x_another=x>>half;
				int x_lower=x&((1<<half)-1);
				int sum=0;
				for(int t=0;t<(1<<(k-half));t++){
					if((t&x_another)==x_another){
						sum+=cnt[(t<<half)|x_lower];
					}
				}
				if(sum<v){
					x-=(1<<bit);
				}
			}
			cout<<x<<'\n';
		}
	}
	return 0;
}
