#include <bits/stdc++.h>
using namespace std;
#include <stdio.h> 
long long int fib(int n) { 
        long long int a =0; 
        long long int b = 1; 
        long long int c = 1; 
        for (int j=2 ; j<=n ; j++) 
        { 
            c =  a+(b); 
            a = b; 
            b = c; 
        } 
  
        return (a); 
    }  
int main(){
	int q;cin>>q;
	while(q-->0){
		long long int n;cin>>n;
		cout<<fib(n+3)%1000000007<<endl;		
	}
	return 0;
}
