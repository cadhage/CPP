#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
	int sum=0;
	for(char c:s){
		sum+=(int)(c-'a')+1;
	//	cout<<c<<" "<<sum;
	}
	cout<<sum<<'\n';
	return 0;
}
