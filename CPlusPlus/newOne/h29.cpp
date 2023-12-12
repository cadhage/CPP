#include <bits/stdc++.h>
using namespace std;
#define MAX 500
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a,b;cin>>a>>b;
	map<char,int> hm;
	for(int i=0;i<a.size();i++){
		hm[a[i]]=hm[a[i]]+1;
	}
	string s="";
	for(int i=0;i<b.size();i++){
		if(hm[b[i]]<=1)
			s+=b[i];
	}
	cout<<s<<'\n';
	return 0;
}
