#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  priority_queue<int,vector<int>> q;
  int n;cin>>n;
  for(int i=0;i<n;i++){
  	int x;cin>>x;
  	q.push(x);
  }
  int qq;cin>>qq;
  for(int i=0;i<qq;i++){
  	int c;cin>>c;
  	if(c==1){
  		int x;cin>>x;
  		q.push(x);
	}else if(c==2){
		cout<<q.top()<<'\n';
	}
  }
  return 0;
}

