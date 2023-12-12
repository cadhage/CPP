#include <bits/stdc++.h>
using namespace std;
int solverUtil(int a,int b,int m){
	if(b==0)
		return 1;
	if(b%2==0)
		solverUtil(a*a%m,b/2,m);
	else (a*solverUtil(a*a%m,(b-1)/2,m))%m;
}
int x,y;
void modInverse(int a,int b){
	if(b==0)
	{
		x=1;
		y=0;
	}
	else{
		modInverse(b,a%b);
		int temp=x;
		x=y;
		y=temp-(a/b)*y;
	}
}
int MODInverse(int a,int m){
	modInverse(a,m);
	return (x%m+m)%m;
}
void solver(int a,int b,int m){
	a=a%m;
	int inv=MODInverse(b,m);
	if(inv==-1){
		cout<<"Div Not define";
	}
	else cout<<(inv*a)%m;
}
int main(){
	solver(8,3,5);
}
