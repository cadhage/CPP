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
	for(ll i=2;i<=N;i++){
		if(prime[i])
			prime[i]=i;
	}

	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		vector<ll> v;
		v.push_back(1);
		for(int i=2;i<=n;i++){
			if(prime[i])
				v.push_back(i);
		}
		ll sum=0,mul=1;
		for(int it:v){
			sum+=it;
		//	cout<<it<<' ';
			mul=(mul*it)%MOD;
		}
		//cout<<sum<<' '<<mul<<'\n';
		sum%mul==0?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
}
