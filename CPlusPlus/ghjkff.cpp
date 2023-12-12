#include <bits/stdc++.h>
using namespace std;
vector<string> dp[100][100];
void findCombination(int k){
	string s="";
	for(int i=0;i<=k;i++){
		dp[i][0].push_back(s);
		s=s+"0";
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=i;j++){
			for(string s:dp[i-1][j])
				dp[i][j].push_back("0"+s);
			for(string s:dp[i-1][j-1])
				dp[i][j].push_back("1"+s);
		}
	}
	for(int i=1;i<=k;i++){
		for(string str:dp[k][i])
			cout<<s<<" ";
		cout<<endl;
	}
}
int main(){
	int k=5;
	findCombination(k);
	return 0;
}
