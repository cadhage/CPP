#include <bits/stdc++.h>
using namespace std;
int dp[100][100][100];
int length(int a,int b,int c){
	if(dp[a][b][c]!=-1)
		return dp[a][b][c];
	if(a==0 && b==0)
		return dp[a][b][c]==c;
	if(b==0 && c==0)
		return dp[a][b][c]==b;
	if(b==0 && c==0)
		return dp[a][b][c]==a;
	if(a==0)
		return dp[a][b][c]=length(a+1,b-1,c-1);
	if(b==0)
		return dp[a][b][c]=length(a-1,b+1,c-1);
	if(c==0)
		return dp[a][b][c]=length(a-1,b-1,c+1);
	int mn=min(length(a-1,b-1,c+1),length(a+1,b-1,c-1));
	mn=min(mn,length(a-1,b+1,c-1));
	return dp[a][b][c]=mn;
}
int stringReduction(string s){
	int n=s.length();
	int count[3]={0};
	//int n=s.size();
	for(int i=0;i<n;i++){
		count[s[i]-'a']++;
	}
	for(int i=0;i<=count[0];i++){
		for(int j=0;j<count[1];j++){
			for(int k=0;k<count[2];k++){
				dp[i][j][k]=-1;
			}
		}
	}
	return length(count[0],count[1],count[2]);
}
int main(){
	string s="abcbbaacb";
	cout<<stringReduction(s);
	return 0;
}
