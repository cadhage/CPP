#include <bits/stdc++.h>
using namespace std;
void print(string s){
	int n=s.size();
	int pow_set=pow(2,n);
	for(int i=0;i<pow_set;i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j))
				cout<<s[j];
		}
		cout<<endl;
	}
}
int main(){
	string s="1234";
	print(s);
	return 0;
}
