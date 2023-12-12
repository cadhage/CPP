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
	ll n;cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	ll max=LONG_MIN,min=LONG_MAX;
	for(ll i=0;i<n;i++){
		if(prime[a[i]])
		{
			if(max<a[i])
				max=a[i];
			if(min>a[i])
				min=a[i];
		}
	}
	cout<<min<<' '<<max;
// 	if(max==1 ||min==1)
// 		return -1;
// 	else max-min<0?cout<<-1<<'\n':cout<<max-min<<'\n';
	return 0;
}
