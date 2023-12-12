#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	stack<int> stk;
	vector<int> a(n),v[n],nge(n);
 	for(int i=0;i<n;++i)
 		cin>>a[i];
 		for(int i=0;i<n;++i){
			while(!stk.empty() && a[stk.top()]<a[i])
  				nge[stk.top()]=i,stk.pop();
  			stk.push(i);
 		}
 	while(!stk.empty())
 	nge[stk.top()]=-1,stk.pop();
 	for(int i=0;i<n;++i){
	 	int cur=i;
 		while(cur!=-1 && nge[cur]<n)
  		v[i].push_back(cur),cur=nge[cur];
  		v[i].push_back(n);
 	}
 	int q;
	cin>>q;
 	while(q--)
 	{
 		int l,r;
 		cin>>l>>r;
  		int x=upper_bound((v[l]).begin(),v[l].end(),r)-v[l].begin();
  		cout<<x<<"\n";
 	}
	return 0;
}
