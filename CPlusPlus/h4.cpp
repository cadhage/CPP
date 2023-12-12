#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n;cin>>n;
  vector<int> arr;
  while(n>0){
  	arr.push_back(n%10);
  	n/=10;
  }
	vector<int> a(arr.size());
	for(int i=0;i<arr.size();i++){
		a[i]=arr[arr.size()-i-1];
	}
	int digit=0;
	bool flag=true;
	for(int i=0;i<a.size();i++){
		digit=10*digit+a[i];
		if(digit%(a.size()-i)!=0){
			cout<<"No"<<'\n';
			flag=false;
			break;
		}
	}
	if(flag)
		cout<<"Yes\n";
  return 0;
}

