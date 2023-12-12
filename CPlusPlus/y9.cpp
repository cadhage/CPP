#include <bits/stdc++.h>
using namespace std;
#define N 1000000
#define ll long long int
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> prime(N,1);
	vector<ll> v(N,0);
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
		string s;cin>>s;
		vector<int> count(256,0);
		for(int i=0;i<s.size();i++){
			count[s[i]]++;
		}
		int c=0,p=0;
		bool flag=false;
		for(int i=0;i<count.size();i++){
			if(count[i]>0){
				if(count[i]==1){
					flag=true;
					break;
				}
				if(prime[count[i]]){
					p++;
				}
				c++;
				
			}
		}
		if(flag)
			cout<<"NO\n";
		else if(prime[c])
			c==p?cout<<"YES\n":"NO\n";
		else cout<<"NO\n";
	}
	return 0;
}
