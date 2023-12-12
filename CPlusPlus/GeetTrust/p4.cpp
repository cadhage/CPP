#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tt;cin>>tt;
	for(int ii=0;ii<tt;ii++){
		string s;cin>>s;
		if(s.size()==1){
			cout<<"Case #"<<(ii+1)<<": "<<0<<'\n';
			continue;
		}
		map<char,int> mp;
		int a_count=0,e_count=0,i_count=0,o_count=0,u_count=0;
		int c_count=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='A')
				a_count++;
			else if(s[i]=='E')
				e_count++;
			else if(s[i]=='I')
				i_count++;
			else if(s[i]=='O')
				o_count++;
			else if(s[i]=='U')
				u_count++;
			else c_count++;
			mp[s[i]]++;
		}

		if(a_count==0 && e_count==0 && i_count==0 && o_count==0 && u_count==0){
			cout<<"Case #"<<(ii+1)<<": "<<s.size()<<'\n';
			continue;
		}
		for(auto it:mp){
			cout<<it.first<<" "<<it.second<<'\n';
		}
	//	cout<<c_count<<" "<<a_count<<" "<<e_count<<" "<<i_count<<" "<<o_count<<" "<<u_count<<'\n';
//		int mx=max(a_count,max(e_count,max(i_count,max(o_count,u_count))));
//		if(mx==a_count)
//			cout<<"Case #"<<(ii+1)<<": "<<c_count+(2*e_count+2*i_count+2*o_count+2*u_count)<<'\n';
//		else if(mx==e_count)
//			cout<<"Case #"<<(ii+1)<<": "<<c_count+(2*a_count+2*i_count+2*o_count+2*u_count)<<'\n';
//		else if(mx==i_count)
//			cout<<"Case #"<<(ii+1)<<": "<<c_count+(2*e_count+2*a_count+2*o_count+2*u_count)<<'\n';
//		else if(mx==u_count)
//			cout<<"Case #"<<(ii+1)<<": "<<c_count+(2*e_count+2*i_count+2*a_count+2*u_count)<<'\n';
//		else if(mx==o_count)
//			cout<<"Case #"<<(ii+1)<<": "<<c_count+(2*e_count+2*i_count+2*o_count+2*a_count)<<'\n';
	}
	return 0;
}

