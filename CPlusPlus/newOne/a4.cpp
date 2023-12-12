#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
bool V[1000];
void addEdge(int a,int b){
	adj[a-1].push_back(b-1);
	adj[b-1].push_back(a-1);
}
void dfs(int i,int a[],int mn) 
{ 
	mn=min(mn,a[i]);
    V[i]=true;
	for(auto it:adj[i]){
		if(!V[it]){
			dfs(it,a,mn);
		}
	} 
}   
int minimumSumConnectedComponents(int a[], int n) 
{ 
    // Initially sum is 0 
    int sum = 0; 
  
    // Traverse for all nodes 
    for (int i = 0; i < n; i++) { 
        if (!V[i]) { 
            int mini = a[i]; 
            dfs(i, a, mini); 
            sum += mini; 
        } 
    } 
      
    // Returns the answer 
    return sum; 
} 
int main() 
{ 
    addEdge(1, 2); 
    addEdge(3, 4); 
    addEdge(5, 6); 
    addEdge(7, 8); 
    addEdge(9, 10);  
   	int a[] = {1, 6, 2, 7, 3, 8, 4, 9, 5, 10};
	 int n=sizeof(a)/sizeof(a[0]); 
   	cout << minimumSumConnectedComponents(a, n);
    return 0; 
}
