#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fl(i,a,b) for(int i=a;i<b;i++)
#define nl(i,a,b) for(int i=a;i>=b;i--)
#define FIO ios::sync_with:stdio(false);cin.tie(0);
#define pb push_back
const int N=129;
int seq[N],last[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fl(i,2,N){
		if(last[seq[i-1]]){
			seq[i]=(i-1)-last[seq[i-1]];
		}
		last[seq[i-1]]=i-1;
	}
	ll tt;cin>>tt;
	while(tt--){
		ll n;cin>>n;
		ll ans=0;//n;cin>>n;
		fl(i,1,n+1){
			if(seq[i]==seq[n])
				ans++;
		}
		cout<<ans<<'\n';
	}
    return 0;
}
