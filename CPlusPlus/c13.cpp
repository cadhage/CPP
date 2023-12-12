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
		//pair<int,int> a[n];
		ll a[8]={0};
		fl(i,0,n){
			ll x,y;cin>>x>>y;
			if(x>8)
				continue;
			a[x-1]=max(a[x-1],y);	
		}
		ll sum=0;
		for(auto x:a){
			sum+=x;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
