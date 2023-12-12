#include <bits/stdc++.h>
using namespace std;
int solver(string s){
	int sum=(int)(s[0]-'0');
	for(int i=1;i<s.size()-1;i++){
		if(s[i]=='+'){
			sum=(sum+(int)(s[i+1]-'0'));
		} 
		if(s[i]=='-') {
			sum=(sum-(int)(s[i+1]-'0'));
//			cout<<sum<<" ";	
		}
	}
	return sum;
}
int main(){
	int n;cin>>n;
	int mx=0;
	while (n--)
	{
		string b;cin>>b;
    	int x=solver(b);
    	mx=max(x,mx);
	}
	cout<<mx;
	return 0;
}
