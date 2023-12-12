#include<bits/stdc++.h> 
using namespace std; 
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define MAX 1000009
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0); 
int s[MAX]; 
int e[MAX]; 
vector<int>dfs_order; 
vector<int>adj[MAX]; 
int v[MAX]; 
void addEdge(int x,int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void dfs(int a,int &time) 
{ 
	v[a]=1; 
	time++; 
	s[a]=time; 
	dfs_order.push_back(a); 
	for(auto it:adj[a]) 
	{ 
		if(!v[it]) 
		{ 
			dfs(it,time); 
		} 
	} 
	e[a]=time; 
} 
vector<pair<int,vector<int>>> vect;
bool is_prime(int n) 
{ 
    if (n <= 1) 
        return false; 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
    return true; 
} 
int primeFactors(int n)  
{  
	int c=0;
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        cout << 2 << " ";  
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            c++;
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        c++;
	return c; 
}  
void solver() 
{ 
	vector<int> sol(MAX,0);
	for(int i = 0; i <MAX; i++) 
	{ 
		if(s[i]!=e[i]) 
		{ 
			set<int> set;
			for(int j=s[i]+1;j<=e[i];j++) 
			{ 
				set.insert(dfs_order[j-1]); 
			}
			int xr=0;
			for(int i=0;i<dfs_order.size();i++){
				if(set.find(dfs_order[i])==set.end()){
					if(is_prime(dfs_order[i])){
						xr^=dfs_order[i];
						cout<<dfs_order[i]<<' ';
					}
				}
			}
			cout<<'\n';
			//cout<<primeFactors(xr)+1<<'\n'; 
		} 
	} 
} 
int main() 
{ 
	int n, count = 0;
	cin>>n;
	vector<int> a(n);
	fl(i,0,n){
		cin>>a[i];
	}
	fl(i,1,n){
		int x;cin>>x;
		addEdge(a[i],a[x-1]);
	}
	dfs(a[0], count); 
	solver(); 
	return 0; 

} 

