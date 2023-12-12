#include<bits/stdc++.h>  
using namespace std; 
int dp[1000][1000]={0};
string longestRepeatedSubSeq(string s){
	int n=s.size();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1]==s[j-1]&& i!=j)
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	string res="";
	int i=n,j=n;
	while(i>0 &&j>0){
		if(dp[i][j]==dp[i-1][j-1]+1){
			res=res+s[i-1];
			i--;j--;
		}
		else if(dp[i][j]==dp[i-1][j])
			i--;
		else j--;
	}
	reverse(res.begin(),res.end());
	return res;	
} 
int main()  
{  
    string str = "AABEBCDD"; 
    cout << longestRepeatedSubSeq(str);  
    return 0;  
}  
