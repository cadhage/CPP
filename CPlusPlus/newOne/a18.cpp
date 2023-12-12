#include <bits/stdc++.h>
using namespace std;
bool areConsecutive(int a[],int n){
	if(n<1)
		return false;
	int min=*min_element(a,a+n);
	int max=*max_element(a,a+n);
	if (max - min  + 1 == n) 
  	{ 
      int i; 
      for (i = 0; i < n; i++) 
      { 
      	int j=0;
        if (a[i]>0)
		 	j= -a[i]-min;
		else 
			j=a[i]-min;
        if(a[j]>0)
			a[j]=-a[j];
		else 
			return false; 
  	     //visited[a[i] - min] = true; 
      } 
 	  return true; 
  } 
	return false;
}
int main(){
	int arr[]= {5, 4, 2, 3, 1, 6}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    if(areConsecutive(arr, n) == true) 
        printf(" Array elements are consecutive "); 
    else
        printf(" Array elements are not consecutive "); 
	return 0;
}
