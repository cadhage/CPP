#include <bits/stdc++.h>
using namespace std;
bool hasOneChild(int a[],int n){
	int mn=-1,mx=-1;
	if(a[n-1]<a[n-2])
	{
		mn=a[n-1];
		mx=a[n-2];
	}
	else{
		mn=a[n-2];
		mx=a[n-1];
	}
	for(int i=n-3;i>=0;i--){
		if(a[i]<mn)
			mn=a[i];
		else if(a[i]>mx)
			mx=a[i];
		else return false;
	}
	return true;
}
int main(){
	int a[]={8,3,5,7,6};
	int n=sizeof a/sizeof(a[0]);
	cout<<hasOneChild(a,n);
	return 0;
}

