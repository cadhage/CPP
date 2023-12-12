#include<bits/stdc++.h>
using namespace std;
int sum(int a[],int s,int e){
	int sum=0;
	for(int i=s;i<=e;i++){
		sum+=a[i];
	}
	return sum;
}
int solver(int a[],int n,int k){
	if(k==1)
		return sum(a,0,n-1);
	if(n==1)
		return a[0];
	int res=INT_MAX;
	for(int i=0;i<n;i++){
		res=min(res,max(solver(a,i,k-1),sum(a,i,n-1)));
	}
	return res;
}
int main(){
	 int arr[] = { 10, 20, 60, 50, 30, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
    cout<<solver(arr,n,k);
	return 0;
}
