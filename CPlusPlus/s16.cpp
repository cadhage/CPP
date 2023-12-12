#include <bits/stdc++.h>
using namespace std;
int aMODM(string a,int m){
	int number=0;
	for(char c:a){
		number=(number*10+(c-'0'));
		number%=m;
	}
	return number;
}
int solver(string a,int b,int m){
	int ans=aMODM(a,m);
	int mul=ans;
	for(int i=1;i<b;i++){
		ans=(ans*mul)%m;
	}
	return ans;
}
int main(){
	string a = "987584345091051645734583954832576"; 
    unsigned int b=3, m=11; 
    cout << solver(a, b, m);
    return 0;
}
