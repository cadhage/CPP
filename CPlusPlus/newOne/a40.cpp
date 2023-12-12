#include <bits/stdc++.h>
using namespace std;
int kadanes(int a[],int n){
	int max=0,ans=0;
	for(int i=0;i<n;i++){
		max+=a[i];
		if(max>ans)
			ans=max;
		if(max<0)
			max=0;
	}
	return ans;
}
int maxCircularSum(int a[],int n){
	int kadane_max=kadanes(a,n);
	int max=0;
	for(int i=0;i<n;i++){
		max+=a[i];
		a[i]=-a[i];
	}
	max+=kadanes(a,n);
	return max>kadane_max?max:kadane_max;
	
}
int main(){
	 int a[] = {11, 10, -20, 5, -3, -5, 8, -13, 10};  
    int n = sizeof(a)/sizeof(a[0]);  
    cout << "Maximum circular sum is " << maxCircularSum(a, n) << endl;  
    return 0;  
}
