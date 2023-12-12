#include <bits/stdc++.h>
using namespace std;
bool solver(string a,string b){
	vector<int> vec(26,0);
	for(int i=0;i<a.size();i++){
		vec[(int)(a[i]-'a')]++;
	}
	for(int i=0;i<b.size();i++){
		vec[(int)(b[i]-'a')]--;
	}
	for(int i=0;i<26;i++)
		if(vec[i]!=0)
			return false;
	return true;
}
int main(){
	int tt;cin>>tt;
	while(tt--){
		string a,b;cin>>a>>b;
		solver(a,b)?cout<<"YES":cout<<"NO";
	}
	return 0;
}
