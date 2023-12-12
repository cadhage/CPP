#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
using namespace std; 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		ll ans=0,temp_x;
		ll x,l,n;cin>>x>>l>>n;
		if (n==0)
            cout << "0\n";
        else if (n>64)
            cout << x << '\n';
        else
            cout << ((x<=(l>>(n-1)))?0:x-(l>>(n-1))) << '\n';
	}
	return 0;
}

