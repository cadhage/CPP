#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fl(i,a,b) for(int i=a;i<b;i++)
#define nl(i,a,b) for(int i=a;i>=b;i--)
int main(){
	ll tt;cin>>tt;
	while(tt--){
		ll n;cin>>n;
		ll ans=0;
		string a,res;cin>>a;
		fl(i,1,n){
			string b;cin>>b;
			ll x=0;
			res="";
			fl(j,0,max(b.size(),a.size())){
				if(a[j]==b[j])
					res+="0";
				else res+="1";	
			}
			a=res;
		//	cout<<res<<'\n';
		}
		ll c=0;
		if(n==1)
			res=a;
		fl(i,0,res.size())
			if(res[i]=='1')
				c++;
		cout<<c<<'\n';
		//cout<<__builtin_popcount(ans)<<'\n';
	}
	return 0;
}
