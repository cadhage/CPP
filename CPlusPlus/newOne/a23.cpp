#include <bits/stdc++.h>
using namespace std;
int countPair(int a[],int n,int k){
	int res=0;
	for(int i=0;i<n;i++){
		res+=upper_bound(a+i,a+n,a[i]+k)-(a+i+1);
	}
	return res;	
}
int kthDiff(int a[],int n,int k){
	sort(a,a+n);
	int low=a[1]-a[0];
	for(int i=1;i<n-1;i++){
		low=min(low,a[i+1]-a[i]);
	}
	int high=a[n-1]-a[0];
	while(low<high){
		int mid=(low+high)>>1;
		if(countPair(a,n,mid)<k)
			low=mid+1;
		else 
			high=mid;
	}
	return low;
}
int main(){
	int k = 3; 
    int a[] = {1, 2, 3, 4}; 
    int n = sizeof(a)/sizeof(a[0]); 
    cout << kthDiff(a, n, k); 
    return 0; 
}
