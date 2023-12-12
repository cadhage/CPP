#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,q;cin>>n>>q;
  vector<int> a(n);
  list<int> lt;
  for(int i=0;i<n;i++){
  	int x;cin>>x;
  	a[i]=x;
  	lt.push_back(x);
  }
  for(int i=0;i<q;i++){
  	int op;cin>>op;
  	for(int j=0;j<op;j++){
  		sort(a.begin(),a.end());
  		lt.push_back(a[a.size()-1-i]-a[i]);
  		lt.remove(a[0]);
  		a.push_back(a[a.size()-1-i]-a[i]);
  		lt.remove(a[a.size()-1]);
	}
	for(auto it:lt)
		cout<<it<<' ';
	cout<<'\n';
  }
  return 0;
}

