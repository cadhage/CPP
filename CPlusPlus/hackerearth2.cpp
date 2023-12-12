#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t-->0){
		string s;cin>>s;
		int n;cin>>n;
		string ss="abcdefghijklmnopqrstuvwxyz";
		for(int i=0;i<n;i++){
			string q;cin>>q;
			for(int k=0;k<q.length();k++){
				if(q[k]==s[i]){
					cout<<ss[i];
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
