#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long int
#define fl(i,a,b) for(int i=a;i<b;i++)
#define nl(i,a,b) for(int i=a;i>=b;i--)
int main(){
	ll t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n],ans=0,t=0,z=0;
		fl(i,0,n){
			int x;cin>>x;
			if(x==0)
				ans+=z++;
			if(x==2)
				ans+=t++;
				
		}
		cout<<ans<<'\n';
	}
	return 0;
}
