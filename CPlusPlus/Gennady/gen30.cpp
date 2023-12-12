#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(n%2==1){
			cout<<"NO"<<'\n';
			continue;
		}
		int ok=1;
		for(int i=0;i<n/2;i++){
			if(a[i]!=-1&& a[i+n/2]!=-1 && a[i]!=a[i+n/2]){
				ok=0;
				break;
			}
			a[i]=max(a[i],a[i+n/2]);
			a[i+n/2]=max(a[i],a[i+n/2]);
			if(a[i]==-1){
				a[i]=a[i+n/2]=1;
			}
			}
			if(!ok){
				cout<<"NO"<<'\n';
				continue;
			}
			cout<<"YES"<<'\n';
			for(int i=0;i<n;i++){
				if(i>0){
					cout<<' ';
				}
				cout<<a[i];
			}
			cout<<"\n";
		}
	return 0;
}
