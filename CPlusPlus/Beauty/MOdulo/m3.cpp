#include <bits/stdc++.h>
using namespace std;
#define M 10000007
int solver(int a,int n){
	if(n==0)
		return 1;
	else if(n%2==0){
		return solver(a*a%M,n/2);
	}
	else return (a*solver(a*a%M,(n-1)/2))%M;
}
int main(){
	cout<<solver(3,10);
	return 0;
}
