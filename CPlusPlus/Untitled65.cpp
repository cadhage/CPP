#include <bits/stdc++.h>
using namespace std;
int maxTasks(int a[],int b[],int n){
	int dp[n+1];
	dp[0]=0;
	dp[1]=a[0];
	for(int i=2;i<=n;i++){
		dp[i]=max(a[i-1]+dp[i-2],b[i-1]+dp[i-1]);
	}
	return dp[n];
}
int main(){
	int n=5;
	int high[] = {3, 6, 8, 7, 6}; 
    int low[] = {1, 5, 4, 5, 3};
    cout<<maxTasks(high,low,n);
	return 0;
}
