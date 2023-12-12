#include <bits/stdc++.h>
using namespace std;
void printSmall(int a[],int n,int k){
	for(int i=k;i<n;i++){
		int max_var=a[k-1];
		int pos=k-1;
		for(int j=k-2;j>=0;j--){
			if(a[j]>max_var){
				max_var=a[j];
				pos=j;
			}
		}
		if(max_var>a[i]){
			int j=pos;
			while(j<k-1){
				a[j]=a[j+1];
				j++;
			}
			a[k-1]=a[i];
		}
	}
	for(int i=0;i<k;i++){
		cout<<a[i]<<' ';
	}
}
int main() 
{ 
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
    int n = sizeof(arr) / sizeof(arr[0]);  
    int k = 5; 
    printSmall(arr, n, k); 
    return 0; 
} 
