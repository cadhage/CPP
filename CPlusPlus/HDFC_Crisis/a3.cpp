#include <bits/stdc++.h>
using namespace std;
void deleteElements(int a[],int n,int k){
	stack<int> s;
	s.push(a[0]);
	int count=0;
	for(int i=1;i<n;i++){
		while(!s.empty()&&s.top()<a[i] && count<k){
			s.pop();
			count++;
		}
		s.push(a[i]);
	}
	int m=s.size();
	vector<int> v(m);
	while(!s.empty()){
		v[--m]=s.top();
		s.pop();
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	int n = 5, k = 2; 
    int arr[] = {20, 10, 25, 30, 40};  
    deleteElements(arr, n, k); 
	return 0;
}
