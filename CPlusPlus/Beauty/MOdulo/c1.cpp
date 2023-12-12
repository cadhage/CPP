#include <bits/stdc++.h>
using namespace std;
int main(){
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		map<int,bool> m;
		char a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			m.insert({a[i],true});
		}
		string s;
		cin>>ws;
		getline(cin,s);
		int c=0;
		for(int i=0;i<s.size();i++){
			auto it = m.find(s[i]); 
		    if(it != m.end()) 
		        //cout << "Key-value pair not present in map\n" ; 
		        //cout << "Key-value pair present : " 
		          c++;
			}
			cout<<c<<'\n';
		}
		//cout<<c<<'\n';
}
