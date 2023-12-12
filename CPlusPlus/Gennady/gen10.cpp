#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n,m;cin>>n>>m;
		vector<int> a(n*2);
		for(int i=0;i<n;i++){
			cin>>a[2*i]>>a[2*i+1];
		}
		sort(a.begin(),a.end());
		for(int i=0;i<m;i++){
			int p;cin>>p;
			int it=(int)(lower_bound(a.begin(),a.end(),p+1)-a.begin());
			if(it==2*n){
				cout<<-1<<'\n';
			}
			else{
				if(it%2==1){
					cout<<0<<'\n';
				}
				else {
					cout<<a[it]-p<<'\n';
				}
			}
		}
	}
	return 0;
}
