#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define ll long long int
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> prime(N,1);
	prime[0]=prime[1]=0;
	for(ll i=2;i<=sqrt(N);i++)
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
	ll tt,mn=0;scanf("%lld",&tt);
	while(tt--){
		ll n;scanf("%lld",&n);
		for(ll i=2;i<=n;i++){
			if(prime[i])
				if(n%i==0){
					mn=i;
					break;
				}
		}
		if(mn==n)
			printf("%d\n",0);
		else printf("%lld\n",n-mn);
	}
	return 0;
}
