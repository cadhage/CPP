// C++ implementation to sort numbers on 
// the basis of factors 
#include <bits/stdc++.h> 
using namespace std; 
bool checkReverse(int a[],int n){
	if(n==1)
		return 1;
	int i;
	for(i=1;i<n&&a[i-1]<a[i];i++);
	if(i==n)
		return true;
	int j=i;
	while (a[j] < a[j-1]) 
    { 
        if (i > 1 && a[j] < a[i-2]) 
            return false; 
        j++; 
    } 
	if(j==n)
		return true;
	int k=j;
	if(a[k]<a[i-1])
		return false;
	while(k>1 &&k<n){
		if(a[k]<a[k-1])
			return false;
		k++;
	}
	return true;
}
int main() 
{ 
	int arr[] = {1, 3, 4, 10, 9, 8};
    int n = sizeof(arr)/sizeof(arr[0]); 
    checkReverse(arr, n)? (cout << "Yes" << endl): 
                          (cout << "No" << endl); 
	return 0; 
} 

