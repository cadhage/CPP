#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
	int x=0,y=0;
	int sum=0;
	for(int i=0;i<s.size();i++){
		sum+=(int)(s[i]-'0')*(i+1);
	}
	sum%11==0?cout<<"Legal ISBN":cout<<"Illegal ISBN";
	return 0;
}
