#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;cin>>tt;
  vector<pair<int,pair<int,int>>> a;
  while(tt--){
  	string s;cin>>s;
  	bool flagA=true,flagB=true;
  	string x="",p="",q="",r="";
  	int count=0,i;
  	vector<int> st;
	for(i=0;i<s.size();i++){
  		if(s[i]=='/'){
  			st.push_back(stoi(x));
  			x="";
		}
		if(s[i]!='/')
			x+=s[i];
		
	}
	st.push_back(stoi(x));
	a.push_back(make_pair(st[0],make_pair(st[1],st[2])));
//	cout<<x<<" "<<s.substr(i,s.size())<<'\n';
 // 	a.push_back(make_pair(i,make_pair(i,i)));
  }
  sort(a.begin(),a.end(),[](auto x,auto y){
		if(x.second.second==y.second.second && x.second.first==y.second.first){
  			return x.first<y.first;
		}
		else if(x.second.second==y.second.second){
  			return x.second.first<y.second.first;
		}
		return x.second.second<y.second.second;
	});
for(auto it:a){
	cout<<it.first<<"/"<<it.second.first<<"/"<<it.second.second<<'\n';
}
  return 0;
}

