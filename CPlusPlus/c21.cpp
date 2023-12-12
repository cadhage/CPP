#include<bits/stdc++.h>
using namespace std;
bool dp[2][100]={false};
bool solver3(vector<int> a,int sum,int n){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(j==0)
				dp[i%2][j]=true;
			else if(i==0)
				dp[i][j]=false;
			if(a[i-1]>j)
				dp[i%2][j]=dp[(i+1)%2][j]+1;
			else
				dp[i%2][j]=dp[(i+1)%2][j]||dp[(i+1)%2][j-a[i]];
		}
	}
}
int main(){
	vector<int> a= {4, 1, 10, 12, 5, 2}; 
    int sum = 9;
    solver3(a,sum,a.size())?cout<<"true\n":cout<<"false\n";
	return 0;
}
