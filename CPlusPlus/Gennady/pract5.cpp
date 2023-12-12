#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<pair<int,int>> next_greater(n);
	vector<int> next_smaller(n);
	for(int i=0;i<n;i++){
		int curr=a[i];
		bool flag=false;
		for(int j=i+1;j<n;j++){
			if(a[j]>curr){
			//	cout<<curr<<"-"<<a[j]<<' ';
				next_greater[i]=make_pair(a[j],j);
				flag=true;
				break;
			}
		}
		if(!flag){
			//cout<<curr<<'-'<<-1<<' ';
			next_greater[i]=make_pair(-1,-1);
			flag=false;
		}
	}
//	for( auto it: next_greater){
//		cout<<it.first<<' '<<it.second<<'\n';
//	}
	for(int i=0;i<n;i++){
		int curr=next_greater[i].first;
		bool flag=false;
		for(int j=next_greater[i].second+1;j<n;j++){
			if(a[j]<curr){
				//cout<<curr<<"-"<<a[j]<<' ';
				next_smaller[i]=a[j];
				flag=true;
				break;
			}
		}
		if(!flag){
//			cout<<curr<<'-'<<-1<<' ';
			next_smaller[i]=-1;
			flag=false;
		}
	}
	cout<<'\n';
	for(auto it:next_smaller){
		cout<<it<<' '; 
	}
	return 0;
}
