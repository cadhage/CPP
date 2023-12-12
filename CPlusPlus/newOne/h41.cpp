#include<bits/stdc++.h>
using namespace std;
map<string,int>dis;
queue<string>q;
int main()
{
	int n;cin>>n;
	string cur,final;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		cur.push_back(char(47+(int)x));
		final.push_back(char(48+i));
	}
	dis[cur]=0;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.front();q.pop();
		if(cur==final)
		{
			cout<<dis[cur]<<'\n';
			return 0;
		}
		for(int i=2;i<=n;i++)
		{
			string nxt=cur;
			reverse(nxt.begin(),nxt.begin()+i);
			if(dis.find(nxt)==dis.end())
			{
				dis[nxt]=dis[cur]+1;
				q.push(nxt);
			}
		}
	}
	cout<<dis.size()<<'\n';
}
