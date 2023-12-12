#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int 
long long int pow(int x,int y){
	if(y==0)
		return 1;
	if(y%2==0){
		return pow(x*x%M,y/2);
	}else{
		return (x*pow(x*x%M,(y-1)/2))%M;
	}	
}
int x,y,d;
void extendedEuclid(int a,int b){
	if(b==0){
		d=a;
		x=1;
		y=0;
	}else{
		extendedEuclid(b,a%b);
		int temp=x;
		x=y;
		y=temp-(a/b)*y;
	}
}
int modInverse(int a,int b){
	extendedEuclid(a,b);
	return (x%M+M)%M;
}
ll GCD_A(int a[],int n){
	ll result=a[0];
	for(int i=1;i<n;i++)
	{
		extendedEuclid(result,a[i]);
		result=d;
	}
	return result;
}
ll _mul(int a[],int n){
	ll ml=1;
	for(int i=0;i<n;i++)
		ml=(ml*a[i])%M;
	return ml;
}
int main() 
{ 
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	ll gcd=GCD_A(a,n);
	ll mul=_mul(a,n);
	cout<<pow(mul,gcd); 
    return 0; 
} 
