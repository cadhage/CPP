#include <bits/stdc++.h>
using namespace std;
int longestCommonSum(vector<bool> a,vector<bool> b,int n){
	int maxLen=0;
	for(int i=0;i<n;i++){
		int sum1=0,sum2=0;
		for(int j=i;j<n;j++){
			sum1+=a[j];
			sum2+=b[j];
			if(sum1==sum2){
				int len=j-i+1;
				if(len>maxLen)
					maxLen=len;
			}
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
