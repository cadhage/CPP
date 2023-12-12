#include <bits/stdc++.h>
using namespace std;

int bfs(int a[],int n) 
{ 
	vector<int> adj[n],v(n,0),level(n,0);
	for(int i=0;i<n;i++){
		adj[a[i]].push_back(i);
	}
    queue<int> q; 
    q.push(0);
	v[0]=1; 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop();
        if(u==n-1){
        	break;
		}
		int d=a[u];
		for(auto it:adj[u]){
			if(!v[it]){
				v[it]=1;
				q.push(it);
				level[it]=level[u]+1;
			}
		} 
	    adj[d].clear();
	     if (u-1 >= 0 && !v[u - 1]) 
        { 
            v[u - 1] = true; 
            q.push(u - 1); 
            level[u - 1] = level[u] + 1; 
        } 
  
        //  checking condition for next index 
        if (u + 1 < n && !v[u + 1]) 
        { 
            v[u + 1] = true; 
            q.push(u + 1); 
            level[u + 1] = level[u] + 1; 
        } 
	}
	return level[n-1]; 
} 
int main() 
{ 
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 5, 
                 4, 3, 6, 0, 1, 2, 3, 4, 5, 7}; 
    int N = sizeof(arr) / sizeof(int); 
    cout << bfs(arr, N); 
    return 0; 
}
