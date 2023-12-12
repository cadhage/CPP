#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,g;
	cin>>n>>m>>g;
	int t[n];
	int a[m];
	//cin>>t[0];
	//a[0]=0;
	for(int i=0;i<n;i++){
		ll x;cin>>a[i];
	}
	ll temp[n];
	for(int i=1;i<n;i++){
		a[i]=a[i]-a[i-1];
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" "<<endl;
	for(int i=1;i<m;i++)
		cin>>a[i];
	
}
