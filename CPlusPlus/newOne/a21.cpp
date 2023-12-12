#include <bits/stdc++.h>
using namespace std;
void productArray(int a[],int n){
	int temp=1;
	vector<int> prod(n,1);
	for(int i=0;i<n;i++){
		prod[i]=temp;
		temp*=a[i];
	}
	temp=1;
	for(int i=n-1;i>=0;i--){
		prod[i]*=temp;
		temp*=a[i];
	}
	for(int i=0;i<n;i++)
		cout<<prod[i]<<' ';
	return;
}
int main(){
	    int arr[] = {10, 3, 5, 6, 2};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    cout << "The product array is: \n";  
    productArray(arr, n);  
	return 0;
}
