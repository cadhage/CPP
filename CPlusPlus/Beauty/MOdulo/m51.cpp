#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll CountBits(ll n){
	ll count=0;
	for(ll i=n;i!=0;i>>=1){
		if(1&i){
			count++;
		}
	}
	return count;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		vector<pair<int,int>> count(10000);
		for(int i=0;i<n;i++){
			int x;cin>>x;
			count.push_back(make_pair(x,CountBits(x)));
		}
		sort(count.begin(),count.end(),[](auto a,auto b){
			return a.second<b.second;	
		});
		int sm=0;
		for(int i=0;i<count.size();i++){
			if(count[i].first!=0)
				cout<<count[i].first<<' ';
		}
		cout<<sm<<'\n';
	}
	return 0;
}
