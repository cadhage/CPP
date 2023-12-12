#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
using namespace std; 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int n;cin >> n;
	ll a[n];
	for(ll i=0;i<n;i++){
	    cin >> a[i];
	}
	ll m;cin >> m;
	ll b[m];
	for(ll i=0;i<m;i++){
	    cin >> b[i];
	}
	ll y=max(a[n-1],b[m-1]);
	for(ll i=0;i<y;i++){
	        ll w=0;
	    for(ll j=0;j<n;j++){
	        for(ll k=0;k<m;k++){
	                if(i+a[j]==b[k]){
	            w++;
	            break;}
	        }
	    }
	    if(w==n){
	        cout << i << " ";
	    }
	}
	return 0;
}

