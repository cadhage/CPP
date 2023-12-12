#include <bits/stdc++.h>
using namespace std;
vector<int> g[100009];
bool v[100009];
void dfs(int s,int &count)
{
    v[s]=true;;
	count++;
    for(auto i:g[s])
    {
        if(!v[i])
        {
        	v[i]=true;
            dfs(i,count);
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m,x;cin>>n>>m>>x;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;x--;y--;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		int  count=0;
		if(!v[i]){
			dfs(i,count);
			if(count>=x){
				cnt++;
			}
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
