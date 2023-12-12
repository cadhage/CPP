#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	map<long long,int> m;
	for(int i=0;i<n;i++){
		long long x;int y;cin>>x>>y;
		m[x+y]++;
	}
	int s;cin>>s;
	long long ans=0;
	for(auto it=m.begin();it!=m.end();it++){
		ans+=it->second*(m[it->first-s]);
	}
	cout<<ans<<endl;
	return 0;
}
