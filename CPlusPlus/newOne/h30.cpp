#include <bits/stdc++.h>
using namespace std;
#define MAX 500
//int get_eq_num(vector<vector<int>> &a){
//	//int c=0;
//	int c0=0,c1=0;
//	for(int i=0;i<a.size();i++){
//		
//		for(int j=0;j<a[i].size();j++){
//		//	cout<<a[i][j]<<' ';
//			if(a[i][j]!=0){
//				break;
//			}
//			if(j==a[i].size()-1) c0++;
//		}
//		for(int j=0;j<a[i].size();j++){
//			if(a[i][j]!=1){
//				break;
//			}
//			if(j==a[i].size()-1) c1++;
//		}
//	//	cout<<'\n';
//	}
//	return c0+c1;
//}
int solver(vector<vector<int>> &a){
	int mx=0;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			if(a[i][j]==1){
				mx++;
				break;
			}
		}
	}
	return mx;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;cin>>n>>m;
	vector<vector<int>> a;
	for(int i=0;i<n;i++){
		vector<int> aa;
		for(int j=0;j<m;j++){
			int x;cin>>x;
			aa.push_back(x);
		}
		a.push_back(aa);
	}
	cout<<solver(a);
	return 0;
}
