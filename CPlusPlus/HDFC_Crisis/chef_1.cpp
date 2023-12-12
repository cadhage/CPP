#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define endl "\n"
 
int32_t main()
{
	fast;
	int t;
	cin>>t;
	vector<int> f(100);
	f[0]=0;
	f[1]=1;
	for(int i=2;i<100;i++)
	{
		f[i]=(f[i-1]+f[i-2])%10;
	}
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int c=0;
		while(n>0)
		{
			c++;
			n/=2;
		}
		c--;
		int x=(int)pow(2, c);
		x--;
		// x%=60;
		cout<<f[x%60]<<endl;
		// cout<<f[x]<<endl;
	}
	return 0;
}
