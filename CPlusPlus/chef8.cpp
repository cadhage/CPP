#include <bits/stdc++.h>
using namespace std;
long computeXOR(const int n) 
{    
    switch(n%4) // n % 4  
    { 
    case 0: return n;     // if n is multiple of 4 
    case 1: return 1;     // If n % 4 gives remainder 1   
    case 2: return n + 1; // If n % 4 gives remainder 2     
    case 3: return 0;     // If n % 4 gives remainder 3   
    } 
} 
int main(){
	int q;cin>>q;
	while(q-->0){
		int a,b;cin>>a>>b;
		int total=computeXOR(b);
		for(int i=1;i<=a;i++){
			total^=i;
		}
		cout<<total<<endl;
		if(total%2==0)	
			cout<<"Even"<<endl;
		else cout<<"Odd"<<endl;
	}
	return 0;
}
