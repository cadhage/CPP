#include <bits/stdc++.h>
using namespace std;
int offering(int a[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		int left=0,right=0;
		for(int j=i-1;j>=0;j--){
			if(a[j]<a[j+1])
				left++;
			else break;
		}
		for(int j=i+1;j<n;j++){
			if(a[j]<a[j-1])
				right++;
			else break;
		}
		sum+=max(left,right)+1;
	}
	return sum;
}
int main(){
	int a[]={1,4,3,6,2,1};
	cout<<offering(a,6);
	return 0;
}
