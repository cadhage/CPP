#include <bits/stdc++.h>
using namespace std;
void solver(string s){
	vector<char> ans;
	for(int i=0;i<s.size();i++){
		if(ans.size()==0 || s[i]!=ans.back())
			ans.push_back(s[i]);
		else ans.pop_back();
	}
	if(ans.size()==0)
		cout<<"Empty String";
	else
	{
		for(auto it:ans)
			cout<<it;
	}
}
int main(){
	string s;cin>>s;
	vector<bool> v(s.size(),true);
	solver(s);
	return 0;
}
