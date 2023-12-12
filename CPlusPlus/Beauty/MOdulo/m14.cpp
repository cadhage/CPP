#include <bits/stdc++.h>
using namespace std;
bool solver(string s){
	if(((int)(s[0]-'0')+(int)(s[1]-'0'))%2!=0)
		return false;
	if(s[2]=='A'||s[2]=='E'||s[2]=='I'||s[2]=='O'||s[2]=='U'||s[2]=='Y')
		return false;
	if(((int)(s[3]-'0')+(int)(s[4]-'0'))%2!=0)
		return false;
	if(((int)(s[4]-'0')+(int)(s[5]-'0'))%2!=0)
		return false;
	if(s[6]!='-')
		return false;
	if(((int)(s[7]-'0')+(int)(s[8]-'0'))%2!=0)
		return false;
	return true;
}
int main(){
    string n;cin>>n;
    solver(n)?cout<<"Valid":cout<<"Invalid";
	return 0;
}
