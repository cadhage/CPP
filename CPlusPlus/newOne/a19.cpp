#include <bits/stdc++.h>
using namespace std;
int minOps(int a[],int n,int k){
	int max=*max_element(a,a+n);
	int res=0;
	for(int i=0;i<n;i++){
		if((max-a[i])%k!=0){
			return -1;
		}
		else res+=(max-a[i])/k;
	}
	return res;
}
int main(){
	 int arr[] = { 21, 33, 9, 45, 63 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 6; 
    cout << minOps(arr, n, k); 
	return 0;
}
