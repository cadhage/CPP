#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	
	cin.tie(0);
	int n,q;cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(q--){
		int sm=0;
		int l,r,x;cin>>l>>r>>x;
		for(int i=l-1;i<r;i++){
			sm+=a[i]^x;
		}
		cout<<sm<<'\n';
	}
	return 0;
}
