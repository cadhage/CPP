#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007  
ll pow(ll x,ll y){
	if(y==0)
		return 1;
	if(y%2==0){
		return pow(x*x%M,y/2);
	}
	else return (x*pow(x*x%M,(y-1)/2))%M;
}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int x,y;cin>>x>>y;
		x=x%M,y=y%(M-1);
		cout<<pow(x,y)<<'\n';
	}
    return 0; 
} 
