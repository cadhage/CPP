#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000]={0};
int count(int  a[],int m,int n){
	for(int i=0;i<m;i++){
		dp[0][i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			int x=(i-a[j]>=0)?dp[i-a[j]][j]:0;
			int y=(j>=1)?dp[i][j-1]:0;
			dp[i][j]=x+y;
		}
	}
	return dp[n][m-1];
}
int main() 
{ 
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 4; 
    cout << count(arr, m, n); 
    return 0; 
} 
 
