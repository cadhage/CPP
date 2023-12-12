#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define ll long long int
int _sum(int n){
	int sum=0;
	while(n>0){
		sum+=n%10;
		n=n/10;
	}
	return sum;
}
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
	for(ll i=2;i<=N;i++){
		if(prime[i])
			prime[i]=i;
	}
	int l,r;cin>>l>>r;
	for(int i=l;i<=r;i++){
		if(prime[i])
		{
			if(prime[_sum(i)])
				cout<<i<<' ';
		}
	}
	return 0;
}
