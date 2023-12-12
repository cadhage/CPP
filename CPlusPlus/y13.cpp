#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define MOD 1000000007
#define ll long long int
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> prime(N,1);

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
	vector<int> isPrime;
	for(ll i=2;i<=N;i++){
		if(prime[i]){
			prime[i]=i;
			isPrime.push_back(i);
		}
	}
	int tt;cin>>tt;
	while(tt--){
		int n,sum=0;cin>>n;
		for(int i=0;i<n;i++){
			sum+=isPrime[i];
		}
		cout<<sum<<'\n';
	}
	return 0;
}
