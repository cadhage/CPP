#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;cin>>q;
	for(int i=0;i<q;i++){
		int n;cin>>n;
		int a,b,k;cin>>a>>b>>k;
		int aa[n];
		int ba[n];
		for(int j=1;j<=n;j++){
			aa[j-1]=j*a;
			ba[j-1]=j*b;
		}
//		for(int j=1;j<=n;j++){
//			cout<<aa[j-1]<<"\n";
//			cout<<ba[j-1]<<"\n";
//		}
		
		int count=0;
		for(int j=0;j<n;j++){
			if((aa[j]<=n || ba[j]<=n) && aa[j]!=ba[j])
				count++;
		}
		if(count==k)
			cout<<"Win"<<"\n";
		else 
			cout<<"Lose"<<"\n";
	}
	return 0;
}
