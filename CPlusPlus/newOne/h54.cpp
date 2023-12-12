// CPP program to find all subsets by backtracking. 
#include <bits/stdc++.h> 
using namespace std;
int dp[10000][10000]; 
bool checkValidPair(int num1, int num2) 
{ 
	string s1 = to_string(num1); 
	string s2 = to_string(num2); 
	for (int i = 0; i < s1.size(); i++) 
		for (int j = 0; j < s2.size(); j++) 
			if (s1[i] == s2[j]) 
				return true; 
	return false; 
}
bool check(int i,int x,int n ){
	for(int j=0;j<n;j++){
		if(checkValidPair(dp[i][j],x))
			return false;
	}
	return true;
}
int main() 
{ 
	int tt;cin>>tt;
	while(tt--){
		memset(dp,0,sizeof dp);
		int n;cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<a.size();i++){
			dp[i][0]=a[0];
			for(int j=0;j<a.size();j++){
				if(!checkValidPair(a[i],a[j])&& check(i,a[j],a.size())){
					dp[i][j]=a[j];
				}
			}
			for(int k=0;k<a.size();k++){
				cout<<dp[i][k]<<' ';
			}
			cout<<'\n';
		}
	}
	return 0; 
} 

