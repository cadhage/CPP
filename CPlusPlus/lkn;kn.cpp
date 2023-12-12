#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;cin>>n;
	while(n-->0){
		int l,k;
		cin>>l>>k;
		if(l%k!=0){
			cout<<"Not Possible"<<endl;
			break;
		}
		multimap<string,int> m ;
		while(l-->0){
			string s;cin>>s;
			m.insert(make_pair(s,s.length()));
		}
		auto i=m.begin();
		int t=i->second;
		int count=0,count2=0;
		for(auto it=m.begin();it!=m.end();it++){
			if(it->second==t)
				count++;
			else
				count2++;
		}
		if(count==count2)
			cout<<"Possible"<<endl;
		else cout<<"Not Possible"<<endl;
	}
	return 0;
}
