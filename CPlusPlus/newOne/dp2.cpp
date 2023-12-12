#include <bits/stdc++.h>
using namespace std;
int binomialCoeff(int n,int k){
	int dp[k+1];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=k;j>0;j--){
			dp[j]=dp[j]+dp[j-1];
		}
	}
	return dp[k];
}
int main(){
	int n = 5, k = 2; 
    printf ("Value of C(%d, %d) is %d ", 
            n, k, binomialCoeff(n, k) ); 
    return 0; 
}

