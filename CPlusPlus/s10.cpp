#include <bits/stdc++.h>
using namespace std;
#define V 4
void tsp(int a[][V],vector<bool> &v,int currPos,int n,int count,int cost,int &ans){
	if(count==n&&a[currPos][0]){
		ans=min(ans,cost+a[currPos][0]);
			return;
	}
	for(int i=0;i<n;i++){
		if(!v[i]&&a[currPos][i]){
			v[i]=true;
			tsp(a,v,i,n,count+1,cost+a[currPos][i],ans);
			v[i]=false;
			
		}
	}
}
int main() 
{ 
    int n = 4; 
    int graph[][V] = { 
        { 0, 10, 15, 20 }, 
        { 10, 0, 35, 25 }, 
        { 15, 35, 0, 30 }, 
        { 20, 25, 30, 0 } 
    };
    vector<bool> v(V,false);
    int ans=INT_MAX;
    v[0]=true;
    tsp(graph,v,0,n,1,0,ans);
    cout<<ans<<'\n';
    return 0;
}
