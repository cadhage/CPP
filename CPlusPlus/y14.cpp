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

		int n;cin>>n;
		int i=0,j=n;
		bool flag=false;
		int min=INT_MAX,diff;
		bool flag=false;
		while(i<=j){
			if((i+j)==n && prime[i] && prime[j] && (j-1)<=min){
				cout<<i<<" "<<j<<'\n';
				diff=j-i;
				flag=true;
				if(diff<min){
					min=diff;
				}
				break;
			}
			else if((i+j)>n){
				j--;
			}
			else i++;
		}
		if(!flag)
			cout<<-1<<'\n';
	return 0;
}
