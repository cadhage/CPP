#include <bits/stdc++.h>
using namespace std;
string printShortestCommonSupersequence(string x,string y){
	int n=x.length(),m=y.length();
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0){
				dp[i][j]=j;
			}
			else if(j==0)
				dp[i][j]=i;
			else if(x[i-1]==y[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
		}
	}
	int index=dp[n][m];
	//return dp[n][m];
	string s;
	int i=n;int j=m;
	while(i>0 && j>0){
		if(x[i-1]==y[j-1]){
			s.push_back(x[i-1]);
			j--;i--;index--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
			s.push_back(y[j-1]);
			j--;index--;
		}
		else{
			s.push_back(x[i-1]);
			i--;index--;
		}
	}
	while(i>0){
		s.push_back(x[i-1]);
		i--,index--;
	}
	while(j>0){
		s.push_back(y[j-1]);
		j--,index--;
	}
	reverse(s.begin(),s.end());
	return s;
}
int main(){
	string X = "AGGTAB"; 
    string Y = "GXTXAYB"; 
  	cout<<printShortestCommonSupersequence(X,Y);
	return 0;
}
