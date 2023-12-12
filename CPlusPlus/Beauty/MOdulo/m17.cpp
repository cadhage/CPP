#include <bits/stdc++.h>
using namespace std;
void solver(string s,int d){
	for(char c:s){
		if(((int)c>=65 && (int)c<=90)){
			cout<<(char)(((c+d)-'A')%26+'A');
		}
		else if((int)c>=97 && (int)c<=122){
			cout<<(char)(((c+d)-'a')%26+'a');
		}
		else if((int)c>=48&&(int)c<=57){
			cout<<(char)(((c+d)-'0')%10+'0');
		}
		else cout<<c;		
	}
}
int main(){
	string s;cin>>s;
	int n;cin>>n;
	solver(s,n);
	return 0;
}
