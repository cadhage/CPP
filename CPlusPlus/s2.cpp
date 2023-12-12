#include <bits/stdc++.h>
using namespace std;
int findMin(int a[],int n,int sumCal,int sum){
	if(n==0)
		return abs((sum-sumCal)-sumCal);
	return min(findMin(a,n-1,sumCal+a[n-1],sum),findMin(a,n-1,sumCal,sum));
}
int main() 
{ 
    int a[] = {3, 1, 4, 2, 2, 1}; 
    int n = sizeof(a)/sizeof(a[0]); 
  	int sum=accumulate(a,a+n,0);
    cout << "The minimum difference between two sets is "
         << findMin(a, n,0,sum); 
    return 0; 
} 
