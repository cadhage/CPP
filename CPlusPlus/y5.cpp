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
	vector<int> prime11;
	int j=0;
	for(int i=0;i<=N;i++){
		if(prime[i]&& i%11==1){
			prime11.push_back(i);
		}
	}
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		auto it=lower_bound(prime11.begin(),prime11.end(),x);
		cout<<*it<<'\n';
	}
//	ll n;cin>>n;
//	vector<ll> a(n);
//	for(int i=0;i<n;i++)
//		cin>>a[i];
	return 0;
}
