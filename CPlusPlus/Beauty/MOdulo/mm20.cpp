#include <bits/stdc++.h>
using namespace std;
bool dfs(int residue,int curr_step,int wt[],int a[],int n,int steps){
	if(curr_step>steps)
		return true;
	for(int i=0;i<n;i++){
		if(a[i]>residue&&a[i]!=wt[curr_step-1])
		{
			wt[curr_step]=a[i];
			if(dfs(a[i]-residue,curr_step+1,wt,a,n,steps))
				return true;
		}
	}
	return false;
}
void printWeightsOnScale(int a[],int n,int steps){
	int wt[steps];
	if(dfs(0,0,wt,a,n,steps)){
		for(int i=0;i<steps;i++){
			cout<<wt[i]<<" ";
		}
		cout<<'\n';
	}else{
		cout<<"Not Possible\n";
	}
}
int main() 
{ 
    int arr[] = {2, 3, 5, 6}; 
    int N = sizeof(arr) / sizeof(int); 
  
    int steps = 10; 
    printWeightsOnScale(arr, N, steps); 
    return 0; 
} 
