#include <bits/stdc++.h>
using namespace std;
int getMinDiff(int a[],int n,int k){
	if(n==1)
		return 0;
	sort(a,a+n);
	int ans=a[n-1]-a[0];
	int small=a[0]+k;
	int big=a[n-1]-k;
	if(small>big)
		swap(small,big);
	for(int i=1;i<n;i++){
		int sub=a[i]-k;
		int add=a[i]+k;
		if(sub>=small || add<=big){
			continue;
		}
		if(big-sub<=add-small)
			small=sub;
		else big=add;
	}
	return min(ans,big-small);
}
int main(){
	int a[]={4,6};
	int n=2;
	int k=10;
	cout<<getMinDiff(a,n,k);
	return 0;
}
