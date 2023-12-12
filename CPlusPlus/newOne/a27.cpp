#include <bits/stdc++.h>
using namespace std;
int findFirstMissing(int a[],int s,int e){
	if(s>e)
		return e+1;
	if(s!=a[s])
		return s;
	int mid=(s+e)>>1;
	if(a[mid]==mid)
		return findFirstMissing(a,mid+1,e);
	return findFirstMissing(a,s,mid);
}
int main() 
{ 
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Smallest missing element is " << 
        findFirstMissing(arr, 0, n-1) << endl; 
} 
 
