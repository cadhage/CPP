#include <bits/stdc++.h>
using  namespace std;
int interpolationSearch(int a[],int low,int high,int x){
	if(low<high){
		int mid=low+(x-a[low])*(high-low)/(a[high]-a[low]);
		if(a[mid]==x)
			return mid;
		if(a[mid]>x){
			return interpolationSearch(a,low,mid-1,x);
		}
		else return interpolationSearch(a,mid+1,high,x);
	}
	return -1;
}
int main(){
	    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 
                 22, 23, 24, 33, 35, 42, 47}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    int x = 18; // Element to be searched 
    int index = interpolationSearch(arr,0, n-1, x); 
  
    // If element was found 
    if (index != -1) 
        cout << "Element found at index " << index; 
    else
        cout << "Element not found."; 
	return 0;
}
