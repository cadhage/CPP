#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll x,y,s,t;cin>>x>>y>>s>>t;
	int c=0;
	for(int i=x;i<=x+s;i++)
	{
		for(int j=y;j<=y+s;j++)
		{
			if((i+j)<=t)
				c++;
		}
	}
	cout<<c;
	return 0;
}
