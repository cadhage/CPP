#include <bits/stdc++.h>
using namespace std;
void solver(string a,string b){
	vector<int> count(256,0);
	for(int i=0;i<a.size();i++){
		count[a[i]]++;
	}
	for(int i=0;i<b.size();i++){
		count[b[i]]--;
	}
	int c=0;
	for(int i=0;i<256;i++){
		if(count[i]!=0)
			c+=abs(count[i]);
	}
	cout<<c<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--){
		string a,b;cin>>a>>b;
		solver(a,b);
	}
	return 0;
}
