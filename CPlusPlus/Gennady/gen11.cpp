#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		string s;cin>>s;
		int bal=0;int ans=0;
		for(char c:s){
			if(c=='1'){
				bal++;
			}
			else if(bal==0){
				bal++;ans++;
			}
			else{
				bal--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
