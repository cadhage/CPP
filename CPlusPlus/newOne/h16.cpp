#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	while(n--)
	{
		ll l,r;
			cin >> l >> r;
		if(l<=3 && r>=3)
			cout << "-11\n";
		else if(l<3 && r<3)
		{
			ll ans;
			ans=2*r*r-12*r+7;
			cout << ans << "\n";
		}
		else if(l>3 && r>3)
		{
			ll ans;
			ans=2*l*l-12*l+7;
			cout << ans << "\n";
		}
	}
return 0;
}
