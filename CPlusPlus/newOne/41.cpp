#include <bits/stdc++.h>
using namespace std;
#define MAX 500
vector<int> g[100000];
bool v[10000];
int level[100000];
void bfs(int s) {
        list<int> q;
        q.push_back(s);
        v[ s ] = true;
        level[s]=1;
        while(!q.empty())
        {
            int p = q.front();
            q.pop_front();
            for(auto it:g[p])
            {
                if(!v[ it])
                {
				    level[ it] = level[ p ]+1;                 
                    q.push_back(it);
                    v[it] = true;
      			}
            }
        }
    }
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		x--;y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int x;cin>>x;
	x--;
	bfs(0);
	for(int i=0;i<n;i++)
	if(x==i)
		cout<<level[i]+1<<'\n';
}
