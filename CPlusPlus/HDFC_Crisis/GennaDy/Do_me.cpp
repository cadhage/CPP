#include  <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	set<char> t;
	for(char c:s){
		t.insert(c);
	}
	cout<<t.size()<<'\n';
	return 0;
}
