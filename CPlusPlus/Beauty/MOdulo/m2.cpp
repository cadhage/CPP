#include <bits/stdc++.h>
using namespace std;
int solver(int a,int b){
	if(b==0)
		return 1;
	return a*solver(a,b-1);
}
int main(){
	cout<<solver(5,3)<<"\n";
	return 0;
}
