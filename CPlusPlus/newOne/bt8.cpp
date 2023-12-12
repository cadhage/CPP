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
		NodeData temp=q.front();
		q.pop();
		if(i<a.size() &&(a[i]<temp.data && a[i]>temp.min)){
			q.push({a[i++],temp.min,temp.data});
		}
		if(i<a.size()&& (a[i]>temp.data && a[i]<temp.max)){
			q.push({a[i++],temp.data,temp.max});
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
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	levelOrderBST(a)?cout<<"Yes":cout<<"No"; 
	return 0;
}
