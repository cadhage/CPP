#include<bits/stdc++.h>
using namespace std;
bool solver(vector<int> a,int sum,int n){
	if(sum<a[n-1])
		return solver(a,sum,n-1);
	if(sum!=0 && n==0)
		return false;
	if(sum==0)
		return true;
	return solver(a,sum-a[n-1],n-1)||solver(a,sum,n-1);
}
bool dp[1000][1000]={0};
bool solver2(vector<int> a,int sum,int n){
	for(int i=0;i<=n;i++)
		dp[i][0]=true;
	for(int i=1;i<=sum;i++)
		dp[0][i]=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(a[i-1]>j)
				dp[i][j]=dp[i-1][j];
			if(j>=a[i-1]) 
				dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
		}
	}
	return dp[n][sum];
}
bool dp1[100][100]={false};
bool solver3(vector<int> a,int sum,int n){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(j==0)
				dp1[i%2][j]=true;
			else if(i==0)
				dp1[i%2][j]=false;
			else if(a[i-1]<=j)
				dp1[i%2][j]=dp1[(i+1)%2][j-a[i-1]]||
							dp1[(i+1)%2][j];
			else dp1[i%2][j]=dp1[(i+1)%2][j];
		}
	}
	return dp1[n%2][sum];
}
void display(const vector<int>& v) 
{ 
    for (int i = 0; i < v.size(); ++i) 
        printf("%d ", v[i]); 
    printf("\n"); 
} 
void prnt(vector<int> &arr, int i, int sum, vector<int> &p) 
{ 
    // If we reached end and sum is non-zero. We print 
    // p[] only if arr[0] is equal to sun OR dp[0][sum] 
    // is true. 
    if (i == 0 && sum != 0 && dp[0][sum]) 
    { 
        p.push_back(arr[i]); 
        display(p); 
        return; 
    } 
  
    // If sum becomes 0 
    if (i == 0 && sum == 0) 
    { 
        display(p); 
        return; 
    } 
  
    // If given sum can be achieved after ignoring 
    // current element. 
    if (dp[i-1][sum]) 
    { 
        // Create a new vector to store path 
        vector<int> b = p; 
        prnt(arr, i-1, sum, b); 
    } 
  
    // If given sum can be achieved after considering 
    // current element. 
    if (sum >= arr[i] && dp[i-1][sum-arr[i]]) 
    { 
        p.push_back(arr[i]); 
        prnt(arr, i-1, sum-arr[i], p); 
    } 
} 
 
void solver2a(vector<int> a,int sum,int n){
	for(int i=0;i<=n;i++)
		dp[i][0]=true;
	for(int i=1;i<=sum;i++)
		dp[0][i]=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(a[i-1]>j)
				dp[i][j]=dp[i-1][j];
			if(j>=a[i-1]) 
				dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
		}
	}
	vector<int> p;
	prnt(a,n-1,sum,p);
}
int main(){
	vector<int> a= {4, 1, 10, 12, 5, 2}; 
    int sum = 9;
    cout<<"Method 1: ";
    solver(a,sum,a.size())?cout<<"true\n":cout<<"false\n";
    cout<<"Method 2: ";
    solver2(a,sum,a.size())?cout<<"true\n":cout<<"false\n";
    cout<<"Method 2a: ";
   solver2a(a,sum,a.size());
    cout<<"Method 3:  ";
    solver3(a,sum,a.size())?cout<<"true":cout<<"false";
	return 0;
}
