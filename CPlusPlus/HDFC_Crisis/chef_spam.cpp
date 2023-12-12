#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n,mn,mx;cin>>n>>mn>>mx;
		ll w=1,b=0,wi,bi;
		while(n--){
			cin>>wi>>bi;
			w=w*wi,b=bi+b*wi;
			w%=2;
			b%=2;
		} 
		if(w%2==0){
			if(b)
				cout<<0<<" "<<(mx-mn+1)<<'\n';
			else
				cout<<(mx-mn+1)<<" "<<0<<'\n';
		}
		else{
			ll even =mx/2-(mn-1)/2,odd=(mx-mn+1)-even;
			if(b)
				cout<<odd<<' '<<even<<'\n';
			else 
				cout<<even<<' '<<odd<<'\n';
		}
	}
	return 0;
}
/*
    while(t--){
        int n, mn, mx;
        cin >> n >> mn >> mx;
        ll w = 1, b = 0, wi, bi;
        while(n--){
            cin >> wi >> bi;
            w = w*wi, b = bi+b*wi;
            w %= 2;
            b %= 2;
        }
        if(w % 2 == 0){
            if(b) cout << 0 << " " << (mx - mn + 1) << '\n';
            else cout << (mx - mn + 1) << " " << 0 << '\n';
        }
        else{
            ll even = mx/2 - (mn - 1)/2, odd = (mx - mn + 1) - even;
            if(b) cout << odd << " " << even << '\n';
            else cout << even << " " << odd << '\n';
        }
    }
*/
