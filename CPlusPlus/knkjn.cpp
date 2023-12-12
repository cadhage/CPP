#include<bits/stdc++.h>
using namespace std;
int solver(int n){
	if(n==2 || n==3 ||n==5||n==7)
		return 1;
	int r=min((n-2),min((n-3),min((n-5),(n-7))));
	return r>0?1+solver(r):0;		
}
int main()
{
    int t;
    cin>>t;
    while(t-->0){
    	int n;cin>>n;
    	cout<<solver(n)<<endl;
	}
}
