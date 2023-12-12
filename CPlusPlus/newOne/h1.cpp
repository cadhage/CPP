#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) ((a*b)/__gcd(a,b))
#define MOD 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a[40];
	fill(a,a+40,0);
 	a[0]=1;
	 for(int i=1;i<31;i++){
	 	a[i]=(a[i-1]*2);
	 } 
	 cout<<'\n';
	 int tt;cin>>tt;
	 int cnt,temp;
	 while(tt--){
	 	ll n;cin>>n;
	 	cnt=0;
	 	for(int c=n;c!=0;c>>=1){
	 		if(c&1)
	 			cnt++;
		 }
		 cout<<n+1-a[cnt]<<" "<<a[cnt]<<'\n';
	 }
}
