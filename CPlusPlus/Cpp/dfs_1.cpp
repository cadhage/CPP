#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
vector<bool> v(10000,0),rec(10000,0);
void addEdge(int x,int y){
	adj[x].push_back(y);
}
double findProbability(int m,int n,int i,int j,int N){
	if(j<0||i<0||i>=n||j>=m)
		return 0.0;
	if(N==0)
		return 1.0;
	double prob=0.0;
	prob+=findProbability(n,m,i-1,j,N-1)*0.25;
	prob+=findProbability(n,m,i+1,j,N-1)*0.25;
	prob+=findProbability(n,m,i,j-1,N-1)*0.25;
	prob+=findProbability(n,m,i,j+1,N-1)*0.25;
	return prob;
}
int main() 
{ 
    // matrix size 
    int m = 5, n = 5; 
  
    // coordinates of starting point 
    int i = 1, j = 1; 
  
    // Number of steps 
    int N = 2; 
  
    cout << "Probability is "
        << findProbability(m, n, i, j, N); 
  
    return 0; 
} 
