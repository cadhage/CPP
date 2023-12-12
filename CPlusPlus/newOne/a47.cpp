#include <bits/stdc++.h>
using namespace std;
int longestCommonSum(vector<bool> a,vector<bool> b,int  n){
	int maxLen=0;
	int sum1=0,sum2=0;
	vector<int> diff(2*n+1,-1);
	for(int i=0;i<n;i++){
		sum1+=a[i];
		sum2+=b[i];
		int curr_diff=sum1-sum2;
		int diffIndex=n+curr_diff;
		if(curr_diff==0)
			maxLen=i+1;
		else if(diff[diffIndex]==-1){
			diff[diffIndex]=i;
		}
		else{
			int len=i-diff[diffIndex];
			if(len>maxLen)
				maxLen=len;
		} 
	}
	return maxLen;
}
int main(){
	vector<bool> a={0,1,0,1,1,1,1};
	vector<bool> b={1,1,1,1,1,0,1};
	int n=a.size();
	cout<<longestCommonSum(a,b,n);
	return 0;
}
