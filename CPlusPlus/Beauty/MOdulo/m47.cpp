#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll CountBits(string s,ll n){
	ll count=0;
	for(char c:s){
		if(c=='0'){
			count++;
		}
	}
	return count;
}
int main(){
	ios_base::sync_with_stdio(false);
	
	cin.tie(0);
	//int n;cin>>n;
	int tt;cin>>tt;
	while(tt--){
		ll n;cin>>n;
		string s;cin>>s;
		cout<<CountBits(s,n)<<'\n';
	}
	return 0;
}
