 #include <bits/stdc++.h>
 using namespace std;
 int solve(int a[],int n){
 	int cnt=0;
 	vector<int> parent(n+1,-1);
 	vector<int> vis(n+1,0);
 	for(int i=0;i<n;i++){
 		int j=i;
 		if(parent[j]==-1){
 			while(parent[j]==-1){
 				parent[j]=i;
 				j=(j+a[j]+1)%n;
			 }
			 if(parent[j]==i){
			 	while(!vis[j]){
			 		vis[j]=1;
			 		cnt++;
			 		j=(j+a[j]+1)%n;
				 }
			 }
		 }
	 }
	 return cnt;
 }
int main() 
{ 
    int A[] = { 0, 0, 0, 2 }; 
    int n = sizeof(A) / sizeof(A[0]); 
    cout << solve(A, n); 
    return 0; 
}
