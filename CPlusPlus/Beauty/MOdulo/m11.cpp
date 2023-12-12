#include <bits/stdc++.h>
using namespace std;
void solver(string s){
	for(char c:s){
		if((int)c>=97 && (int)c<=122)
			cout<<char((c-'a')+'A');
		if((int)c>=65 && (int)c<=90) 
			cout<<char((c-'A')+'a');
	}
}
int main(){
    string n;cin>>n;
    solver(n);
	return 0;
}
