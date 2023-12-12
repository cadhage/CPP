#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		int n;cin>>n;
		vector<int> v(n);
		vector<int> p(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		for(int i=0;i<n;i++)
			cin>>p[i];
		bool flag=true;
		sort(p.begin(),p.end());
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++){
			if(v[i]>=p[i]){
				flag=false;
			//	cout<<i<<"\n";
			}
		}
		if(flag){
			cout<<"WIN"<<'\n';
		}else{
			cout<<"LOSE"<<'\n';
		}
	}
	return 0;
}
