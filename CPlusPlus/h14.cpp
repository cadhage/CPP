#include <bits/stdc++.h>

using namespace std;
int solver(int a[],int n){
	int mask=0,mx=0;
	set<int> set;
	for(int i=30;i>=0;i--){
		mask|=(1<<i);
		for(int j=0;j<n;j++){
			set.insert(a[j]&mask);
		}
		int mxx=mx|(1<<i);
		for(auto it:set){
			if(set.count(mxx^it)){
				mx=mxx;
				break;
			}
		}
		set.clear();
	}
	return mx;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int arr[] = { 25, 10, 2, 8, 5, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  cout<<solver(arr,n);
  return 0;
}

