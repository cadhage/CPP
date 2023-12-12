#include <bits/stdc++.h>
using namespace std;
int solver(vector<int> a){ //kadane
	int sum=a[0],max_sum=a[0];
	for(int i=1;i<a.size();i++){
		sum=max(a[i],sum+a[i]);
		max_sum=max(max_sum,sum);
	}
	return max_sum;
}
int main(){
	vector<int> a={1,-3,1,2,3};
	cout<<solver(a)<<'\n';
}
