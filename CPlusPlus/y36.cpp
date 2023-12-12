#include <bits/stdc++.h>
using namespace std;
const int MAX=100;
int getMax(int a[],int n){
	int max=0,max_i=-1;
	for(int i=0;i<n;i++){
		if(a[i]>max){
			max=a[i];
			max_i=i;
		}
	}
	return max_i;
}
int getMin(int a[],int n){
	int min=INT_MAX,min_i=-1;
	for(int i=0;i<n;i++){
		if(a[i]<min){
			min=a[i];
			min_i=i;
		}
	}
	return min_i;
}
void minCashFlowRec(int a[],int n){
	int mxCr=getMax(a,n),mxDb=getMin(a,n);
	if(a[mxCr]==0&&a[mxDb]==0){
		return;
	}
	int mn=min(-a[mxDb],a[mxCr]);
	a[mxCr]-=mn;
	a[mxDb]+=mn;
	cout<<mxDb<<"->"<<mn<<"->"<<mxCr<<'\n';
	minCashFlowRec(a,n);
}
void minCashFlow(int a[][MAX],int n){
	int amount[n]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			amount[i]+=(a[i][j]-a[j][i]);
		}
	}
	minCashFlowRec(amount,n);
}
int main() 
{ 
    // graph[i][j] indicates the amount that person i needs to 
    // pay person j 
    int graph[][MAX] = { {0, 1000, 2000}, 
                        {0, 0, 5000}, 
                        {0, 0, 0},}; 
  
    // Print the solution 
    minCashFlow(graph,3); 
    return 0; 
}
