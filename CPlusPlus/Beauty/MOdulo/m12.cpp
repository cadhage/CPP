#include <bits/stdc++.h>
using namespace std;
bool solver(string s){
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])
			return false;
	}
	return true;
}
int main(){
    string n;cin>>n;
    solver(n)?cout<<"YES":cout<<"NO";
	return 0;
}
