#include <bits/stdc++.h>
using namespace std;
#define N 985621241
#define M 1000000007
#define ll long long int
ll x,y,d;
void eE(ll a,ll b){
	if(b==0){
		d=a;
		y=0;
		x=1;
	}
	else{
		eE(b,a%b);
		ll temp=x;
		x=y;
		y=temp-(a/b)*y;
	}
}
ll MI(ll n){
	eE(n,M);
	return (x%M+M)%M;
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
	int tt;cin>>tt;
	while(tt--){
		ll n;cin>>n;
		cout<<MI(n)<<'\n';
	}
	return 0;
}
