#include <bits/stdc++.h>
using namespace std;
void solver(int n){
	if(n&1!=0){
		if(n==1)
			cout<<-1<<'\n';
		int c=(n*n+1)/2;
		int b=(n*n-1)/2;
		cout<<b<<" "<<c<<"\n";
	}
	else{
		if(n==2)
			cout<<-1<<'\n';
		int c=(n*n)/4+1;
		int b=(n*n)/4-1;
		cout<<b<<" "<<c<<'\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solver(3);
	return 0;	
}
