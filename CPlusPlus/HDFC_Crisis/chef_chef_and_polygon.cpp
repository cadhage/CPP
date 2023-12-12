#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll tt;cin>>tt;
	while(tt--){
		ll n,a,k;
		cin>>n>>a>>k;
		ll total=(n-2)*360;
		ll ans=total-2*a*n;
		ll sol=a*n*(n-1)+(k-1)*ans;
		ll v=n*(n-1);
		ll gcd=__gcd(sol,v);
		sol/=gcd;
		v/=gcd;cout<<sol<<' '<<v<<'\n';
	}
	return 0;
}
/* 19741226
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int tc;cin>>tc;
    while(tc--)
    {
        long long int n,a,k;
        cin>>n>>a>>k;
        long long int total=(n-2)*360;
        long long int ans=total-2*a*n;
        long long int solution=a*n*(n-1)+(k-1)*ans;
        long long int v=n*(n-1);
        long long int gcd=__gcd(solution,v);
        solution/=gcd;
        v/=gcd;
        cout<<solution<<" "<<v<<endl;
    }
}

*/
