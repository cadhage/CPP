#include <bits/stdc++.h>
using namespace std;
#define MAX 500
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		string s;cin>>s;
		for(int i=0;i<s.size();i++){
			cout<<(int)s[i];
		}
		cout<<'\n';
	}
	return 0;
}
