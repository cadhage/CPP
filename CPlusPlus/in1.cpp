#include <bits/stdc++.h>
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
int main(){
	fast_io;
	ll n,count=0;cin>>n;
	queue<ll> a,b;
	fl(i,0,n){
		ll x;cin>>x;
		a.push(x);
	}
	fl(i,0,n){
		ll x;cin>>x;
		b.push(x);
	}
	while(a.size())
	{
		if(a.front()==b.front()){
			a.pop(); 
			b.pop();
		}
		else
		{
			while(a.front()!=b.front())
			{
				int c=a.front(); 
				a.pop(); 
				a.push(c); 
				count++;
			}
		}
	}
	cout<<count+n;
	return 0;
}
