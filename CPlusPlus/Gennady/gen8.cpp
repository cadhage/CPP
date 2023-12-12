#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		long long n;cin>>n;
		vector<long long> a(n,0);
		for(int i=0;i<n;i++){
			int x;cin>>x;
			x--;
			if(0<=x&& x<n){
				a[x]=1;
			}
		}
		cout<<n-accumulate(a.begin(),a.end(),0)<<'\n';
	}
	return 0;
}
