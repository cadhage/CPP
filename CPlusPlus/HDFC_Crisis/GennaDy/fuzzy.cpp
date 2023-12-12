#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		long long a0,b0,c0,a1,b1,c1;
		cin>>a0>>b0>>c0>>a1>>b1>>c1;
		long long a=a1-a0;
		long long b=b1-b0;
		long long c=c1-c0;
		if(a0==0 && b0==0 && c0==0 && c1==0 && b1==0 && a1==0){
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		if(a0==0&& b0==0 &&c0==0){
			if((a1&1)+(b1&1)+(c1&1)==1||(a1&1)+(b1&1)+(c1&1)==2)
				ans=1;
			else
				ans=2;
		}
		else{
			if(a1==0 && b1==0 && c1==0){
				if(((a0&1)+(b0 &1)+(c0&1))==1||((a0&1)+(b0 &1)+(c0&1))==2)
					ans=1;
				else ans=2;
			}
			else{
				if((a&1)!=(b&1)||(b&1)!=(c&1)){
					ans=1;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
