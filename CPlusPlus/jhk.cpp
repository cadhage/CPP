#include <bits/stdc++.h>
using namespace std;
int maxProfit(int a[],int n,int k){
	int dp[k+1][n+1];
	for(int i=0;i<n;i++)
		dp[i][0]=0;
	for(int j=0;j<n;j++)
		dp[0][j]=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			int max_so_far=INT_MIN;
			for(int k=0;k<j;k++){
				max_so_far=max(max_so_far,a[j]-a[k]+dp[i-1][k]);
			}
			dp[i][j]=max(dp[i][j-1],max_so_far);
		}
	}
	return dp[k][n-1];
}
int main(){
	   int k = 2; 
    int price[] = { 10, 22, 5, 75, 65, 80 }; 
    int n = sizeof(price) / sizeof(price[0]); 
  
    cout << "Maximum profit is: "
         << maxProfit(price, n, k);  
	return 0;
}
