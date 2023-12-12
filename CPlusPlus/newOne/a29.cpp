#include <bits/stdc++.h>
using namespace std;
int sumArr(int a[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	return sum;
}
int maxDiff(int a[],int n,int k){
	sort(a,a+n);
	int sum=sumArr(a,n);
	int diff1=abs(sum-2*sumArr(a,k));
	reverse(a,a+n);
	int diff2=abs(sum-2*sumArr(a,k));
	return max(diff1,diff2);
}
int main(){
	int arr[] = {1, 7, 4, 8, -1, 5, 2, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int k = 3; 
    cout << "Maximum Difference = " << maxDiff(arr,n,k); 
	return 0;
}
