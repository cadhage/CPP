#include <bits/stdc++.h>
using namespace std;
void segregate0and1(int a[],int n){
	int l=0,r=n-1;
	while(l<r){
		if(a[l]==1){
			swap(a[l],a[r]);
			r--;
		}
		else l++;
	}
}
// Driver program 
int main() 
{ 
    int arr[] = { 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    segregate0and1(arr, n); 
    for (int a : arr) 
        cout << a << " "; 
} 
