#include <bits/stdc++.h>
using namespace std;
int maxSum(int a[],int n){
	int sum=0,currVal=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		currVal+=i*a[i];
	}
	int mx=currVal;
	for(int i=1;i<n;i++){
		int nextVal=currVal-(sum-a[i-1])+(n-1)*a[i-1];
		currVal=nextVal;
		mx=max(mx,nextVal);
	}
	return mx;
}
int main() 
{ 
    int arr[] = {8, 3, 1, 2}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << maxSum(arr, n) << endl; 
    return 0; 
} 
