#include <bits/stdc++.h>
using namespace std;
void leftRotate(int a[],int d,int n){
	int gcd=__gcd(d,n);
	for(int i=0;i<gcd;i++){
		int temp=a[i];
		int j=i;
		while(true){
			int k=j+d;
			if(k>=n)
				k=n-k;
			if(k==i)
				break;
			a[j]=a[k];
			j=k;
		}
		a[j]=temp;
	}
}
void printArray(int arr[], int size) 
{ 
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " "; 
} 
 
int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function calling 
    leftRotate(arr, 2, n); 
    printArray(arr, n); 
	return 0;
}
