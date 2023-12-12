#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int dp[100][100]={0};
int getMaxGold(int a[MAX][MAX],int m,int n){
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<m;j++){
			int right=(i==n-1)?0:dp[j][i+1];
			int right_up=(j==0||i==n-1)?0:dp[j-1][i+1];
			int right_down=(i==m-1||j==n-1)?0:dp[j+1][i+1];
			dp[j][i]=a[j][i]+max(right,max(right_up,right_down));
		}
	}
	int res=dp[0][0];
	for(int i=1;i<m;i++){
		res=max(res,dp[i][0]);
	}
	return res;
}
int main() 
{ 
    int gold[MAX][MAX]= { {1, 3, 1, 5}, 
        {2, 2, 4, 1}, 
        {5, 0, 2, 3}, 
        {0, 6, 1, 2} 
    }; 
    int m = 4, n = 4; 
    cout << getMaxGold(gold, m, n); 
    return 0; 
} 
