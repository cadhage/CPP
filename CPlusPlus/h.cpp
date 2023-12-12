#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	map<string,int> m;
	for(int i=0;i<s.length()-1;i++){
		for(int j=i+1;j<s.length();j++){
			cout<<s.substr(i,j)<<endl;
			m.insert({s.substr(i,j),0});
		}
	}
	for(auto &it:m){
		cout<<it.first<<" "+it.second<<endl;
	}
	return 0;
}
