#include <bits/stdc++.h>
using namespace std;
void rearrange(vector<int> &a){
	sort(a.begin(),a.end());
	vector<int> temp(a.size());
	int index=0;
	int n=a.size();
	for(int i=0,j=n-1;i<n/2,j>n/2;i++,j--)
	{
		temp[index]=a[i];
		index++;
		temp[index]=a[j];
		index++;
	}
	for(int i=0;i<n;i++){
		a[i]=temp[i];
	}
}
int main(){
	vector<int> a={5,8,1,4,2,9,3,7,6};
	rearrange(a);
	for(auto it:a){
		cout<<it<<' ';
	}
	return 0;
}
