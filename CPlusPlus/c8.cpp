#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long int
#define fl(i,a,b) for(int i=a;i<b;i++)
#define nl(i,a,b) for(int i=a;i>=b;i--)
string solver(string s){
	string ans="";
	int c=0;
	fl(i,0,s.size()){
		c++;
		if(i+1>=s.size()||s[i]!=s[i+1]){
			ans+=s[i];
			ans+=to_string(c);
			c=0;
		}
	}
	return ans.size()<s.size()?ans:s;
}
int main(){
	ll t;cin>>t;
	while(t--){
		string s;cin>>s;
		int ans=solver(s).size();
		if(ans<s.size()){
			cout<<"YES"<<'\n';
		}
		else cout<<"NO\n";
	}
	return 0;
}
