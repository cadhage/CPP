#include <bits/stdc++.h>
using namespace std;
int solver(string s){
	int numbers[]={6,2,5,5,4,5,6,3,7,6};
	for(int i=0;i<s.size();i++){
		cout<<numbers[(int)(s[i]-'0')]<<' ';
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		string n;cin>>n;
		cout<<solver(n)<<'\n';
	}
	return 0;
}
