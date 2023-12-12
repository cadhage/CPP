#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define ll long long int
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> prime(N,1);
	vector<ll> v;
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
		for(int i=2;i<=n;i++){
			if(prime[i])
				v.push_back(i);
		}
		int sum=0;
		for(int it:v){
			int nn=it;
			//int sum=0;
			int i=1,j=it-1,c=0;
			while(i<j){
				if((i+j)==nn){
					i++;j--;
					c++;
				}
				else if((i+j)>nn){
					j--;
				}
				else i++;
			}
			//cout<<nn<<' '<<c<<'\n';
			sum+=c;
			c=0;
		}
		cout<<sum%1000000007<<'\n';
	}
	return 0;
}
