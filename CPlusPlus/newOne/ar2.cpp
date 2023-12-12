#include <bits/stdc++.h>
using namespace std;
int maxSum(int a[],int n){
	int sum=0;
	int currVal=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		currVal+=(i*a[i]);
	}
	int max=currVal;
	for(int i=1;i<n;i++){
		currVal+=sum-(n*a[n-i]);
		if(max<currVal){
			max=currVal;
		}
	}
	return max;
}
int main(void) 
{ 
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Max sum is " << maxSum(arr, n); 
    return 0; 
} 
