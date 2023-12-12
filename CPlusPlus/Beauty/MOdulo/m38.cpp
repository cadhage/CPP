#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//int tt;cin>>tt;
	//while(tt--){
		int n;
		cin>>n;
		int a[n]; 
		for(int i=0;i<n;i++){
			cin>>a[i];	
		}
		int q;cin>>q;
		while(q--){
		int l,r;cin>>l>>r;
		int xr=a[l-1];
		int o=0;
		if(xr==0)
			o=1;
		for(int i=l;i<r;i++){
			xr^=a[i];
			if(a[i]==0)
				o++;
		}
		cout<<xr<<" "<<o<<'\n';
		}
	return 0;
}
