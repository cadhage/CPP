#include <bits/stdc++.h>
using namespace std;
int maxRevenue(int m,int x[],int revenue[],int n,int t){
	int max_rev[m+1];
	memset(max_rev,0,sizeof(max_rev));
	int nextbb=0;
	for(int i=1;i<=m;i++){
		if(nextbb<n){
			if(x[nextbb]!=i)
				max_rev[i]=max_rev[i-1];
			else{
				if(i<=t)
					max_rev[i]=max(max_rev[i-1],revenue[nextbb]);
				else
					max_rev[i]=max(max_rev[i-t-1]+revenue[nextbb],max_rev[i-1]);
				nextbb++;
			}
		}
		else
			max_rev[i]=max_rev[i-1];
	}
	return max_rev[m];
}
int main(){
	 int m = 20; 
    int x[] = {6, 7, 12, 13, 14}; 
    int revenue[] = {5, 6, 5, 3, 1}; 
    int n = sizeof(x)/sizeof(x[0]); 
    int t = 5; 
    cout << maxRevenue(m, x, revenue, n, t);
	return 0;
}
