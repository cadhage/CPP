#include <bits/stdc++.h>
using namespace std;
void reverse(int a[],int s,int e){
	while(s<e){
		int temp=a[s];
		a[s]=a[e];
		a[e]=temp;
		s++;e--;
	}
}
void left_rotation(int a[],int d,int n){
	reverse(a,0,d-1);
	reverse(a,d,n-1);
	reverse(a,0,n-1);
}
int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int d = 2; 
  
    // in case the rotating factor is  
    // greater than array length 
    d = d % n;   
      
    // Function calling 
    left_rotation(arr, d, n); 
    for(auto i:arr)
    	cout<<i<<' ';
	return 0;
}
