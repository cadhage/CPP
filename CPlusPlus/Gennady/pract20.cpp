#include <bits/stdc++.h>
using namespace  std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	string s;cin>>s;
	int c=0;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='1'){
			c=n-1-i;
		}
	}
	cout<<c<<'\n'; 
	return 0;
}
