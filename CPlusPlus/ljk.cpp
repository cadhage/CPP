#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;cin>>n>>k;
	int a[2*n];
	for(int i=0;i<2*n;i++){
		cin>>a[i];
	}
	int x[n];int y[n];
	int l=0,m=0;
	for(int i=0;i<2*n;i++){
		if(i%2==0)
			x[l++]=i+1;
		else 
			y[m++]=i+1;
	}
	cout<<endl;
	for(int i:x)
		cout<<i<<" ";
	cout<<endl;
	for(int i:y)
		cout<<i<<" ";
	return 0;
}
