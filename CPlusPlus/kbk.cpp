#include <bits/stdc++.h>
using namespace std;
bool subSetSum(int set[],int sum,int n){
	if(sum==0)
		return true;
	if(n==0 && sum!=0)
		return false;
	if(set[n-1]>sum)
		return subSetSum(set,n-1,sum);
	return subSetSum(set,n-1,sum||subSetSum(set,n-1,sum-set[n-1]));
}
int main(){
	int set[] = {3, 34, 4, 12, 5, 2}; 
  	int sum = 9; 
  	cout<<subSetSum(set,sum,6)<<endl;
	return 0;
}
