#include <bits/stdc++.h>
using namespace std;
int countSubSequences(string s){
	int acount=0;
	int bcount=0;
	int ccount=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='a')
			acount=(1+2*acount);
		else if(s[i]=='b')
			bcount=(acount+2*bcount);
		else if(s[i]=='c')
			ccount=(bcount+2*ccount);
	}
	return ccount;
}
int main(){
	string s="abbc";
	cout<<countSubSequences(s)<<endl; 
	return 0;
	
}
