#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;cin>>tt;
  string s="SSEC";
  while(tt--){
  	long long int n;cin>>n;
  	for(int i=0;i<s.size()-n%s.size();i++){
  		cout<<(int)s[i%s.size()]<<' ';
	}
	cout<<'\n';
  }
  return 0;
}

