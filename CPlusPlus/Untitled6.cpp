#include <bits/stdc++.h>
using namespace std;
int offering(int a[],int n){
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		v.push_back(make_pair(-1,-1));
	}
	v[0]=make_pair(1,0);
	v[n-1]=make_pair(0,1);
	for(int i=1;i<n;i++){
		if(a[i-1]<a[i])
			v[i].first=v[i-1].first+1;
		else v[i].first=1;
	}
	for(int i=n-2;i>=0;i--){
		if(a[i+1]<a[i])
			v[i].second=v[i+1].second+1;
		else v[i].second=1;
	}
	int sum = 0; 
    for (int i = 0; i < n; ++i) 
        sum += max(v[i].first, v[i].second); 
    return sum; 
}
int main(){
	int a[]={1,4,3,6,2,1};
	cout<<offering(a,6);
	return 0;
}
