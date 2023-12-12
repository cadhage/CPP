#include <bits/stdc++.h>
using namespace std;
int LCS(string x,string y,int n,int m){
	int dp[n+1][m+1];
	int result=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0)
				dp[i][j]=0;
			else if(x[i-1]==y[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
				result=max(result,dp[i][j]);
			}	
			else dp[i][j]=0;
		}
	}
	return result;
}
int main(){
	string X = "OldSite:GeeksforGeeks.org"; 
    string Y = "NewSite:GeeksQuiz.com";
	cout<<LCS(X,Y,X.size(),Y.size()); 
	return 0;
}
