#include <bits/stdc++.h>
using namespace std;
int sum(int n){
	int ans=0;
	while(n>0){
		ans+=n%10;
		n=n/10;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	map<long long,int> m; 
	//int res=0;
	int ans=0;
	int collusion=0;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		int res=x;
		res=x^(sum(x));
		ans=max(ans,res);
		if(m.find(res)!=m.end())
		{
			collusion++;
			m[res]++;
		}
	}
	if(collusion){
		int count=0;
		auto it=m.begin();
		count=it->second;
			ans=it->first;
	for(;it!=m.end();it++){
		if(it->second>count){
			count=it->second;
			ans=it->first;
		}
		else if(count==it->second){
			ans=min(ans,it->second);
		}
		}
	}
	cout<<ans<<" "<<collusion;
	return 0;
}
