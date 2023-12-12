#include <bits/stdc++.h> 
using namespace std;
int fib(int n,int p,int fp,int q,int fq){
	if(n==p)
		return fp; 
	if(n==q)
		return fq;
	return fib(n-1,p,fp,q,fq)+fib(n-2,p,fp,q,fq);
}
int main() 
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout<<fib(10,0,1,6,13);
//	//cout<<fib(10);
//	int tt;
//	cin>>tt;
//	while(tt--){
//		int p,fp;cin>>p>>fp;
//		int q,fq;cin>>q>>fq;
//		cout<<
//	}
	return 0; 
} 

