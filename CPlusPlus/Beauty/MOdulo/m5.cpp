#include <bits/stdc++.h>
using namespace std;
#define M 1000007
int x,y,sol;
void gcd(int a,int b){
	if(b==0){
		sol=a;
		x=1;
		y=0;
	}
	else{
		gcd(b,a%b);
		int temp=x;
		x=y;
		y=temp-(a/b)*y;
	}
}
int main(){
	gcd(5,12);
	cout<<(x%12+12)%12;
	return 0;
}
