#include <bits/stdc++.h>
#include <regex>
#include <iomanip>
using namespace std;
int main(){
	string data="gijg<h1>fjkglk</h1>";
	smatch m;
	bool found=regex_search(data,m,regex("<(.*)>.*</(\\1)>"));
	cout<<"m.empty()"<<" "<<boolalpha<<" "<<m.empty()<<" "<<m.size()<<'\n';
	cout<<m.str()<<" "<<m.length()<<" "<<m.position()<<" "<<m.prefix()<<" "<<m.suffix()<<'\n';
	cout<<m.size()<<'\n';
	for(int i=0;i<m.size();i++){
		cout<<m[i].str()<<" "<<m.str(i)<<" "<<m.position(i)<<'\n';
	}
	for(auto it:m){
		cout<<it.length()<<'\n';
	}
	return 0;
}
