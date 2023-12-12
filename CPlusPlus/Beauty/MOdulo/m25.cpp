#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
	int x=0,y=0;
	for(char c:s){
		if(c=='L')
			x-=1;
		if(c=='R')
			x+=1;
		if(c=='D')
			y-=1;
		if(c=='U')
			y+=1;
		//cout<<x<<' '<<y<<'\n';
	}
	cout<<x<<' '<<y<<'\n';
	return 0;
}
