#include <bits/stdc++.h>
using namespace std;
#define NOT_IN_STACK 0
#define IN_STACK 1
vector<int> adj[100000];
vector<int> adj1[100000];
void addEdge(int v, int w) 
{ 
	v--;w--;
	adj[v].push_back(w); 
	adj[w].push_back(v);
} 
void dfs(int i,vector<bool> &v,vector<int> &st){
	v[i]=true;
//	cout<<i<<' ';
	for(auto it:adj[i]){
		if(!v[it])
			dfs(it,v,st);
	}
	st.push_back(i);
}
void print(int n,vector<int> a,vector<int> a_sum){
	vector<bool> v(n,false);
	//stack<int> st;

	int sum_k=0,sum_i=0;
	vector<int> x;
	if(a_sum.size()>0){
		for(auto it:a_sum){
			sum_k+=a[a_sum[it]];
			x.push_back(it);
		//	cout<<it<<' ';
		}		
	}
	for(int i=0;i<n;i++){
		vector<int> st;
		if(!v[i]){
			dfs(i,v,st);
		//	cout<<'\n';
		}
		int mx=0,mx_i=-1;
		
		if(st.size()==0){
		//	sum_k+=a[i],sum_i+=i;
			continue;
		}
		for(auto it:st){
			if(a[it]>mx)
			mx=a[it],mx_i=it;
		}
		x.push_back(mx_i);
		int k=0,inj=0;
		for(auto it:st){
			if(it==mx_i){
				k+=a[it];
			}
			else inj+=a[it];
		}
		sum_k+=k,sum_i+=inj;
		//cout<<k<<" "<<inj<<'\n';
	}
	sort(x.begin(),x.end());
 	cout<<sum_k<<' '<<sum_i<<'\n';
 	for(auto it:x)
 		cout<<it+1<<' ';
} 
int main(){
    int n,m;cin>>n>>m;
    vector<int> a(n);
    vector<int> a_sum;
    for(int i=0;i<n;i++)
    	cin>>a[i];
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        addEdge(x,y);
        if(x==y)
        	a_sum.push_back(x);
    }
    vector<int>::iterator ip = std::unique(a_sum.begin(), a_sum.end());  
    a_sum.resize(std::distance(a_sum.begin(), ip));
    print(n,a,a_sum);
	return 0;
}
