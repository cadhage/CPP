#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>
using namespace std;
signed main()
{
	int tt;cin>>tt;
	while(tt--){
        vector<ll> temp;
		ll a, b;cin >> a>>b;
		if (a <= 2) {
			a = 2;
			if (b >= 2) {
				temp.pb(a);
				a++;
			}
		}
		if (a % 2 == 0)
			a++;
		for (ll i = a; i <= b; i = i + 2) {
			bool flag = 1;
			for (ll j = 2; j * j <= i; ++j) {
				if (i % j == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				temp.pb(i);
		}
        if(temp.size()==0)
			cout<<-1<<'\n';
		else 
			cout<<*max_element(temp.begin(),temp.end())-*min_element(temp.begin(),temp.end())<<'\n';
	}

	return 0;
}
