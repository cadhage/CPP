#include <bits/stdc++.h>
using namespace std;
void modify(vector<int> &a){
	int n=a.size();
	if(n<=1)
		return;
	int prev=a[0];
	a[0]=a[0]*a[1];
	for(int i=1;i<n-1;i++){
		int curr=a[i];
		a[i]=prev*a[i+1];
		prev=curr;
	}
	a[n-1]=prev*a[n-1];
}
int main(){
	vector<int> a={2,3,4,5,6};
	modify(a);
	for(auto it:a){
		cout<<it<<' ';
	}
	return 0;
}
