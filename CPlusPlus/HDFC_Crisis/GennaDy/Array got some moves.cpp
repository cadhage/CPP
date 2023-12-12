#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		long long n,k;
		cin>>n>>k;
		cout<<k*(k+1)/2+(n-k)<<'\n';
	}
	return 0;
}
