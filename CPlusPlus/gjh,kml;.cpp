#include <bits/stdc++.h>
using namespace std;
int getMaxRec(string s,int i,int n,int dp[]){
	if(i>=n)
		return 0;
	if(dp[i]!=-1)
		return dp[i];
	int ans=1+getMaxRec(s,i+1,n,dp);
	if(i+1<n){
		if(s[i]!=s[i+1])
			ans=max(4+getMaxRec(s,i+2,n,dp),ans);
		else 
			ans=max(3+getMaxRec(s,i+2,n,dp),ans);
	}
	return dp[i]=ans; 
}
int getMax(string s){
	int n=s.size();
	int dp[n];
	fill(dp,dp+n,-1);
	return getMaxRec(s,0,n,dp);
}
int main(){
	string s = "AAAAABB";
	cout<<getMax(s);
	return 0;
}
