#include <bits/stdc++.h>
using namespace std;
int findMaxAverage(vector<int> a,int n,int k){
	if(k>n)
		return -1;
	int sum=a[0];
	for(int i=1;i<k;i++)
		sum+=a[i];
	int max_sum=sum,max_end=k-1;
	for(int i=k;i<n;i++){
		sum+=a[i]-a[i+1];
		if(sum>max_sum){
			max_sum=sum;
			max_end=i;
		}
	}
	return max_end-k+1;
}
int main(){
	vector<int> a={1,12,-5,-6,50,3};
	int k=4;
	int n=a.size();
	cout<<findMaxAverage(a,n,k);
	return 0;
}
