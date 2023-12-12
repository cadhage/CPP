#include<bits/stdc++.h>
using namespace std;
struct NodeData{
	int data,min,max;
};
bool levelOrderBST(vector<int> a){
	int n=a.size();
	if(n==0)
		return true;
	int i=0;
	queue<NodeData> q;
	q.push({a[i++],INT_MIN,INT_MAX});
	while(!q.empty()){
		NodeData b=q.front();
		q.pop();
		if(i<n && a[i]<b.data && a[i]>b.min){
			q.push({a[i++],b.min,b.data});
		}
		if(i<n && a[i]>b.data && a[i]<b.max){
			q.push({a[i++],b.data,b.max});
		}
	}
	if(i==a.size()){
		return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> a = {7, 4, 12, 3, 6, 8, 1, 5, 10}; 
	levelOrderBST(a)?cout<<"Yes":cout<<"No"; 
	return 0;
}
