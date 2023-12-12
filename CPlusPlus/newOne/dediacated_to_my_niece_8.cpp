#include <bits/stdc++.h>
using namespace std;
int dp[100]={1};
int pre[100]={-1};
int largestSubset(int a[],int n){
	sort(a,a+n);
	int max_i=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]%a[j]==0)	
			{
				if(dp[i]<dp[j]+1){
					dp[i]=dp[j]+1;
					pre[i]=j;
				}				
			}
		}
		if(dp[max_i]<dp[i])
			max_i=i;
	}
	int k=max_i;
	while(k>=0){
		cout<<a[k]<<' ';
		k=pre[k];
	}
}
int main() 
{ 
    int a[] = {1, 2, 17, 4}; 
    int n = sizeof(a) / sizeof(a[0]); 
    cout << largestSubset(a, n) << endl; 
    return 0; 
} 
