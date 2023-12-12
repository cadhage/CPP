#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long int
#define fl(i,a,b) for(int i=a;i<b;i++)
#define nl(i,a,b) for(int i=a;i>=b;i--)
int main(){
	ll t;cin>>t;
	while(t--){
		ll n,p=0,a=0,c=0;cin>>n;
		string s;cin>>s;
		fl(i,0,s.size()){
			if(s[i]=='P')
				p++;
			else if(s[i]=='A')
				a++;
		}
		if(p==0){
			cout<<n<<'\n';
		}
		else if(0.75>(p*1.0)/s.size()){
			while(0.75>=(p*1.0)/n){
				p++;
				c++;
			}
		}
		if(c>0)
			cout<<c<<'\n';	
	}
	return 0;
}
