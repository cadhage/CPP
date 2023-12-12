#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//int tt;cin>>tt;
	//while(tt--){
		int n,q;
		cin>>n>>q;
		int a[n]; 
		for(int i=0;i<n;i++){
			cin>>a[i];	
		}
		while(q--){
			int l,r,v;cin>>l>>r>>v;
			for(int i=l-1;i<r;i++){
				a[i]=a[i]&v;
				//cout<<a[i]<<' ';
			}
		//	for(int i=0;i<n;i++){
		//		cout<<a[i]<<' ';
		//	}
		//	cout<<'\n';
		}
		for(int i=0;i<n;i++){
				cout<<a[i]<<' ';
			}
	return 0;
}
