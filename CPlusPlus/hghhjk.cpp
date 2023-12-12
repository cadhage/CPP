#include <bits/stdc++.h>
using namespace std;
#define MIN -1000000000
int findMaxValue(int a[],int n){
	if(n<4){
		cout<<"atleat 4 element"<<endl;
		return MIN;
	}
	int dp1[n+1],dp2[n],dp3[n-1],dp4[n-2];
	for(int i=0;i<=n;i++)
		dp1[i]=dp2[i]=dp3[i]=dp4[i]=MIN;
	for(int i=n-1;i>=0;i--)
		dp1[i]=max(dp1[i+1],a[i]);
	for(int i=n-2;i>=0;i--)
		dp2[i]=max(dp2[i+1],dp1[i+1]-a[i]);
	for(int i=n-3;i>=0;i--)
		dp3[i]=max(dp3[i+1],dp2[i+1]+a[i]);
	for(int i=n-4;i>=0;i--)
		dp4[i]=max(dp4[i+1],dp3[i+1]-a[i]);
	return dp4[0];
}
int main(){
	int a[]={4,8,9,2,20};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<findMaxValue(a,n)<<endl;
	return 0;
}
