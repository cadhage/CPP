#include <bits/stdc++.h>
using namespace std;
void leftRotation(int a[],int d,int n){
	int gcd=__gcd(d,n);
	for(int i=0;i<gcd;i++){
		int temp=a[i];
		int j=i;
		while(true){
			 int k=j+d;
			 if(k==i)
			 	break;
			 if(k>=n)
			 	k=k-n;
			 a[j]=a[k];
			 j=k;
		}
		a[j]=temp;
	}
}

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function calling 
    leftRotation(arr, 2, n); 
    for(int i=0;i<n;i++)
    	cout<<arr[i]<<' ';
	return 0;
}
