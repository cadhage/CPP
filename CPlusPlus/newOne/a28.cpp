#include <bits/stdc++.h>
using namespace std;
int FindMaxSum(int a[],int n){
	int inc=a[0];
	int exe=0;
	int exe_new;
	for(int i=1;i<n;i++){
		exe_new=(exe<inc)?inc:exe;
		inc=exe+a[i];
		exe=exe_new;
	}
	return ((inc>exe)?inc:exe);
}
int main() 
{ 
  int arr[] = {5, 5, 10, 100, 10, 5}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  printf("%d \n", FindMaxSum(arr, n)); 
  return 0; 
} 
