#include <bits/stdc++.h>
using namespace std;
int minPyramidCost(int a[],int n){
	int left[n];
	int right[n];
	left[0]=min(a[0],1);
	for(int i=1;i<n;i++)
		left[i]=min(a[i],min(left[i-1]+1,i+1));
	right[n-1]=min(a[n-1],1);
	for(int i=n-2;i>=0;i--){
		right[i]=min(a[i],min(right[i+1]+1,n-i));
	}
	int tot[n];
	for(int i=0;i<n;i++){
		tot[i]=min(right[i],left[i]);
	}
	int max_ind=0;
	for(int i=0;i<n;i++){
		if(tot[i]>tot[max_ind])
			max_ind=i;
	}
	int cost = 0; 
    int height = tot[max_ind]; 
    for (int x = max_ind; x >= 0; --x) 
    { 
        cost += a[x] - height; 
        if (height > 0) 
            --height; 
    } 
    height = tot[max_ind] - 1; 
    for (int x = max_ind + 1; x < n; ++x) 
    { 
        cost += a[x] - height; 
        if (height > 0) 
            --height; 
    } 
    return cost; 
}
int main() 
{
    int arr[] = {1, 2, 3, 4, 2, 1}; 
    int N = sizeof(arr)/sizeof(arr[0]); 
    cout << minPyramidCost(arr, N); 
    return 0; 
} 
