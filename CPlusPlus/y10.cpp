#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define ll long long int
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> prime(N,1);
	vector<ll> v(N,0);
	prime[0]=prime[1]=0;
	for(ll i=2;i*i<=N;i++)
	{
		if(prime[i]){
			for(ll j=i*i;j<=N;j+=i)
			{
				prime[j]=0;
			}
		}
	}
	for(ll i=2;i<=N;i++){
		if(prime[i])
			prime[i]=i;
	}
	ll n,c=0;cin>>n;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if((i+j)!=1 &&prime[i+j])
				c++;	
		}
	}
	if(n==1)
		cout<<0;
	else cout<<c%1000000007;
	return 0;
}
