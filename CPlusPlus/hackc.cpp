#include <bits/stdc++.h>
using namespace std;
	bool check(string s) {
		int count[26];
		cout<<s;
		int count1=0,count2=0;
		for(int i=0;i<s.length();i++)
			++count[s[i]-'A'];
		//System.out.println(Arrays.toString(count));
		for (int i = 0; i <26; i++) {
			if(count[i]%2==0 && count[i]!=0)
				count2++;
			else if(count[i]>0) count1++;
		}
		//System.out.println(count1+" "+count2);
		return count1<=1;
}
int main(){
	int t;cin>>t;
	while(t-->0) {
		int n,q;cin>>n>>q;
		int count=0;
		string s;cin>>s;
		for (int i = 0; i < q; i++) {
			int x,y;cin>>x,y;
			int diff=y-x;
			if(check(s.substr(x-1,diff)))
				count++;
			
		}
		cout<<(count)<<endl;
	}
}
