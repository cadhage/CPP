#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;cin>>tt;
  while(tt--){
  	string s;cin>>s;
	for(int i=0;i<s.size();i++)
		s[i]=s[i]-2;
	cout<<s<<'\n';
  }
  return 0;
}

