#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll n=10e6+6;  
vector<bool> p(n+1,true);
vector<int> ans(n+1,0);
void sieve(int n){
	p[0]=p[1]=false;
	for(int i=2;i*i<=n;i++){
		if(p[i]){
			for(int j=i*i;j<=n;j+=i){
				p[j]=false;
			}
		}
	}
	ans[0] = ans[1] = 0;
	for(int i=2; i<=n ; i++) 
		ans[i] = (p[i]==true) + ans[i-1];
}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int tt;cin>>tt;
	sieve(n);
	while(tt--){
		int x,y;cin>>x>>y;
		if(x>y)
		  swap(x,y);
		cout<<ans[y]-ans[x-1]<<'\n';
	}

    return 0; 
} 
