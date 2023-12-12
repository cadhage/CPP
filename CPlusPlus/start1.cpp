#include <bits/stdc++.h>
using namespace std;
void dp(string s){
	int count=0;
	int n=s.length();
	for(int k=0;k<n;k++){
	for(int i=k;i<n;i++){
		if(s[i]%2==0)
			count++;}
	//	cout<<s[i];
		cout<<count<<" ";
		count=0;
	}
//	return count;
}
int main(){
	string q;cin>>q;
	dp(q);
	return 0;
}
