#include<bits/stdc++.h>
using namespace std;
int solver(int n){
	if(n==2 || n==3 ||n==5||n==7)
		return 1;
	int r=min(solver(n-2),min(solver(n-3),min(solver(n-5),solver(n-7))));
	return solver(r);		
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
