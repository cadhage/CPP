#include <bits/stdc++.h>
using namespace std;
int solver(int n){
	int r=n;
	for(int i=1;i<n;i++){
		r=i+r+(r*i);
		//cout<<r<<' ';
	}
	return r;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n;cin>>n;
	for(int i=0;i<n;i++){
		int k;cin>>k;
		cout<<solver(k)<<'\n';
	}
	return 0;
}
