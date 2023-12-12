#include <bits/stdc++.h>
using namespace std;
int dp[1<<20][2];
int findMinTime(int left_mask,bool turn,int a[],int &n){
	if(!left_mask)
		return 0;
	int res=dp[left_mask][turn];
	if(!res)
		return res;
	int right_mask=((1<<n)-1)^left_mask;
	if(turn==1)
	{
		int minRow=INT_MAX,person;
		for(int i=0;i<n;i++){
			if(right_mask& (1<<i)){
				person=i;
				minRow=a[i];
			}
		}
		res=a[person]+findMinTime(left_mask|(1<<person),turn^1,a,n);
	}
	else{
		if(__builtin_popcount(left_mask)==1){
			for(int i=0;i<n;i++){
				if(left_mask&(1<<i))
				{
					res=a[i];
					break;
				}
			}
		}
		else{
			res=INT_MAX;
			for(int i=0;i<n;i++){
				if(!(left_mask&(1<<i)))
				continue;
				for(int j=i+1;j<n;j++){
					int val=max(a[i],a[j]);
					val+=findMinTime(left_mask^(1<<i)^(1<<j),turn^1,a,n);
					res=min(res,val);
				}
			}
		}
	}
	return res;
}
int findTime(int a[],int n){
	int mask=(1<<n)-1;
	memset(dp,-1,sizeof(dp));
	return findMinTime(mask,0,a,n);
}
int main(){
	 int arr[] = { 10, 20, 30 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << findTime(arr, n); 
	return 0;
}
