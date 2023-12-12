#include<bits/stdc++.h>
using namespace std;
int product(int a[],int n){
	int mx=1,mn=1,ans=0,flag=0;
	for(int i=0;i<n;i++){
		if(a[i]>0){
			mx*=a[i];
			mn=min(mn*a[i],1);
			flag=1;
		}
		else if(a[i]==0){
			mx=1;
			mn=1;
		}
		else{
			int temp=mx;
			mx=max(mx*a[i],1);
			mx=temp*a[i];
		}
		if(ans<mx)
			ans=mx;
	}
	if(flag==0 && ans==1)
		return 0;
	return ans;
}
int main(){
	int a[]={6, -3, -10, 0, 2};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<product(a,n);
}
