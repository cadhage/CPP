#include <bits/stdc++.h>
using namespace std;
void solver(int n,int count){
		bool flag=false;
        for(int i=0;i<100000;i++){
			if(n%2==0)
				n/=2;
			else n=3*n+1;
			if(n==1){
				flag=true;
				cout<<"YES";
				break;
			}
		}
		if(!flag)
			cout<<"NO";
}
int main(){
	int n,q;cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	for(int i=0;i<q;i++){
		int l,r;cin>>l>>r;
		int res=(l+r);
		//cout<<l<<r;
		if((res)%2==0)
			cout<<a[(res)/2-1]<<'\n';
		else cout<<floor((a[(res)/2]+a[(res)/2-1])/2)<<'\n';
	}
	return 0;
}

