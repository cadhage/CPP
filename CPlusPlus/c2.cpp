#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    //fastio;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n;
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	ll temp=n;//ans=INT_MAX;
	    ll lol = 1;
	    ll ans = n;
	    while(n>=lol)
	    {
	      ll temp = (n/(lol*10))*(lol) + n%lol;
	      ans = min(temp,ans);
	      lol*=10;
	    }
	    cout << ans << endl;
	}
	return 0;
}
