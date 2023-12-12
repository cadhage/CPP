#include <bits/stdc++.h>
using namespace std;
void kSmallestPair(vector<int> a,vector<int> b,int k){
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int n=a.size();
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	set<pair<int,int>> my_set;
	pq.push(make_pair(a[0]+b[0],make_pair(0,0)));
	my_set.insert(make_pair(0,0));
	for(int count=0;count<k;count++){
		pair<int,pair<int,int>> temp=pq.top();
		pq.pop();
		int i=temp.second.first;
		int j=temp.second.second;
		cout<<"("<<a[i]<<", "<<b[j]<<")"<<'\n';
		int sum=a[i+1]+b[j];
		pair<int,int> temp1=make_pair(i+1,j);
		if(my_set.find(temp1)==my_set.end()){
			pq.push(make_pair(sum,temp1));
			my_set.insert(temp1);
		}
		sum=a[i]+b[j+1];
		temp1=make_pair(i,j+1);
		if(my_set.find(temp1)==my_set.end()){
			pq.push(make_pair(sum,temp1));
			my_set.insert(temp1);
		}
	}
}
int main() 
{ 
    vector<int> A = {1,3,11}; 
    vector<int> B = {2,4,8}; 
    int K = 4; 
    kSmallestPair(A, B, K); 
    return 0; 
} 
  
