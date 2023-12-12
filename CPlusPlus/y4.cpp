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
	int tt;cin>>tt;
	while(tt--){
		ll n,k,sum=0;cin>>n>>k;
		vector<ll> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		ll c=0;
		for(ll i=0;i<n;i++){
			if(prime[a[i]])
			{
				c++;
				//cout<<a[i]<<'\n';
				if(c%k==0)
					sum+=a[i];
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
