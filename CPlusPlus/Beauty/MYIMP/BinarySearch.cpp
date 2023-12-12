#include <bits/stdc++.h>
using  namespace std;
int BinarySearch(int a[],int low,int high,int x){
	if(low<high){
		int mid=low+(x-a[low])*(high-low)/(a[high]-a[low]);
		if(a[mid]==x)
			return mid;
		if(a[mid]>x){
			return BinarySearch(a,low,mid-1,x);
		}
		else return BinarySearch(a,mid+1,high,x);
	}
	return -1;
}
int exponeantailSearch(int a[],int n,int x)
{
	if(a[0]==x){
		return 0;
	}
	int i=1;
	while(i<n&& a[i]<=x){
		i*=2;
	}
	return BinarySearch(a,i/2,min(i,n),x);
}

int main(){
	    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 
                 22, 23, 24, 33, 35, 42, 47}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    int x = 18; // Element to be searched 
    int index = exponeantailSearch(arr,n, x); 
  
    // If element was found 
    if (index != -1) 
        cout << "Element found at index " << index; 
    else
        cout << "Element not found."; 
	return 0;
}
