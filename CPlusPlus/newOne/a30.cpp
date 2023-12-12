#include <bits/stdc++.h>
using namespace std;
int findXorSum(int a[],int n){
	int sum=0;
	int mul=1;
	for(int i=0;i<30;i++){
		int c_odd=0;
		bool odd=false;
		for(int j=0;j<n;j++){
			if((a[j]&(1<<i))>0)
				odd=!odd;
			if(odd)
				c_odd++;
		}
		for(int j=0;j<n;j++){
			sum+=mul*c_odd;
			if((a[j]&(1<<i))>0){
				c_odd=(n-j-c_odd);
			}
		}
		mul*=2;
	}
	return sum;
}
int main(){
	 int arr[] = { 3, 8, 13 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << findXorSum(arr, n); 
	return 0;
}
