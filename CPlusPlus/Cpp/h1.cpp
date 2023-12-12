#include <bits/stdc++.h>

using namespace std;
//struct Node{
//	int data;
//	Node *next;	
//};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> a;
  stack<int> st;
  for(int i=0;i<n;i++){
  	int x;cin>>x;
  	if(x%2==0){
	  st.push(x);
	  //cout<<x<<'\n';
	}
	else{
		while(!st.empty()){
			a.push_back(st.top());
			st.pop();
		}
		a.push_back(x);
	}
	while(!st.empty()){
		a.push_back(st.top());
		st.pop();
	}
  }
  for(auto it:a)
  	cout<<it<<" ";
  return 0;
}

