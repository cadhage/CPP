#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MOD 1000000007
using namespace std; 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q;cin>>n>>q;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int cmax[n][n];
	int mx=0;
	for(int i=0;i<n;i++){
		int mx=0;
		for(int j=0;j<n;j++){
			mx=max(mx,a[i][j]);
		}
		for(int j=0;j<n;j++){
			cmax[i][j]=mx;
		}
	}
	int rmax[n][n];
	mx=0;
	for(int i=0;i<n;i++){
		int mx=0;
		for(int j=0;j<n;j++){
			mx=max(mx,a[j][i]);
		}
		for(int j=0;j<n;j++){
			rmax[j][i]=mx;
		}
	}
	while(q--){
		int x,y,p,q;cin>>x>>y>>p>>q;
		cout<<min(rmax[x][y],rmax[x][y])<<'\n';
	}
	return 0;
}

