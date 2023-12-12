#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int findWays(int m,int n,int x){
	if (m*n <= x) 
    	return (m*n == x); 
	if (n >= x) 
    	return (n == x);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m && i<=x;i++){
		dp[1][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=x;j++){
			for(int k=1;k<=m && k<j;k++){
				dp[i][j]+=dp[i-1][j-k];
			}
		}
	}
//	 for (int i = 0; i <= n; i++) 
//    { 
//      for (int j = 0; j <= x; j++) 
//        cout <<dp[i][j] << " "; 
//      cout << endl; 
//    }
	return dp[n][x];
}
int main(){
	cout << findWays(4, 2, 1) << endl; 
    cout << findWays(2, 2, 3) << endl; 
    cout << findWays(6, 3, 8) << endl; 
    cout << findWays(4, 2, 5) << endl; 
    cout << findWays(4, 3, 5) << endl;
	return 0;
}
