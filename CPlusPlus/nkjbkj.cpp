#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long t;cin>>t;
	while(t-->0){
		string a,s;cin>>a>>s;
		if(a.length()>s.length()){
			cout<<"NO"<<endl;
			continue;
		}
		int k=a.length();
		long s1[26]={0},s2[26]={0};
		for(int i=0;i<k;i++){
			s1[a[i]-'a']++;
			s1[s[i]-'a']++;}
		bool flag=false;
		for(int i=0;i<26;i++){
			if(s1[i]!=s2[i]){
				flag=true;
				break;
			}
		}
		if(!flag){
			cout<<"YES"<<endl;
			continue;
		}
		int i;
		long n=s.length();
		for(i=k;i<n;i++){
			s1[s[i-k]-'a']--;
			s2[s[i]-'a']++;
			flag=false;
			for(int j=0;j<26;j++){
				if(s1[j]!=s2[j]){
					flag=true;
					break;
				}
			}
			if(!flag){
				cout<<"YES"<<endl;
				break;
			}}
		if(i==n)
		cout<<"NO"<<endl;
	}
	return 0;
}
