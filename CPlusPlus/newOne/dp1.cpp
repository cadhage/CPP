#include <bits/stdc++.h>
using namespace std;

int getUglyNumber(int n){
	int dp[n];
	int i2=0,i3=0,i5=0;
	int nextMul2=2;
	//int nextMul3=3;
	int nextMul5=5;
	int next_Ugly=1;
	dp[0]=1;
	for(int i=1;i<n;i++){
		next_Ugly=min(nextMul2,//min(nextMul3,
		nextMul5);
		dp[i]=next_Ugly;
		if(next_Ugly==nextMul2){
			i2+=1;
			nextMul2=dp[i2]*2;
		}
//		if(next_Ugly==nextMul3){
//			i3+=1;
//			nextMul3=dp[i3]*3;
//		}
		if(next_Ugly==nextMul5){
			i5+=1;
			nextMul5=dp[i5]*5;
		}
	}
	return next_Ugly;
}
int main(){
	cout<<getUglyNumber(5);
	return 0;
}
