#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q;cin>>n>>q;
	vector<string> a(n);
	vector<string> b(n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		string s;
		cin>>s;
		string ext;
		for(int j=s.size()-1;j>=0;j--){
			if(s[j]=='.'){
				ext=s.substr(j+1);
				break;
			}
		}
		string ans="unknown";
		for(int j=0;j<n;j++){
			if(a[j]==ext){
				ans=b[j];
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
