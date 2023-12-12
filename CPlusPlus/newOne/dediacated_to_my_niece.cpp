#include <bits/stdc++.h>
using namespace std;
void mul(int F[2][2],int M[2][2]){
	int x=F[0][0]*M[0][0]+F[0][1]*M[1][0];
	int y=F[0][0]*M[0][1]+F[0][1]*M[1][1];
	int z=F[1][0]*M[0][0]+F[1][1]*M[1][0];
	int w=F[1][0]*M[0][1]+F[1][1]*M[1][1];
	F[0][0]=x;
	F[0][1]=y;
	F[1][0]=z;
	F[1][1]=w;
}
power(int F[][2],int n){
	int M[2][2]={{1,1},{1,0}};
	for(int i=2;i<=n;i++)
		mul(F,M);
}

int fib(int n){
	int F[2][2]={{1,1},{1,0}};
	if(n==0)	
		return 0;
	power(F,n-1);
	return F[0][0];
}
int main(){
	int n=12;
	double phi=(1+sqrt(5))/2;
	cout<<"Method 1: "<<round(pow(phi,n)/sqrt(5))<<"\n";
	cout<<"Method 2: "<<fib(n);
	return 0;
}
