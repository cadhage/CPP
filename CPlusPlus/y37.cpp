#include <bits/stdc++.h>
using namespace std;
const int MAX=100;
struct contact{
	string x,y,z;         
};
void buildGraph(contact a[],int n,int mat[MAX][MAX]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mat[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].x==a[j].x||
			a[i].x==a[j].y||
			a[i].x==a[j].z||
			a[i].y==a[j].x||
			a[i].y==a[j].y||
			a[i].y==a[j].z||
			a[i].z==a[j].x||
			a[i].z==a[j].y||
			a[i].z==a[j].z){
				mat[i][j]=1;
				mat[j][j]=1;
				break;
			}
		}
	}
}
void dfs(int i,int a[][MAX],bool v[],vector<int> &sol,int n){
	v[i]=true;
	sol.push_back(i);
	for(int j=0;j<n;i++){
		if(!v[j] &&a[i][j]){
			dfs(j,a,v,sol,n);
		}
	}
}
void findContacts(contact a[],int n){
	vector<int> sol;
	int mat[MAX][MAX];
	bool v[n];
	for(int i=0;i<n;i++){
		v[i]=0;
	}
	buildGraph(a,n,mat);
	for(int i=0;i<n;i++){
		if(!v[i]){
			dfs(i,mat,v,sol,n);
			sol.push_back(-1);
		}
	}
	for(int i=0;i<sol.size();i++){
		if(sol[i]==-1)
			cout<<'\n';
		else cout<<sol[i]<<' ';
	}
}
int main() 
{ 
    contact arr[] = {{"Gaurav", "gaurav@gmail.com", "gaurav@gfgQA.com"}, 
                     {"Lucky", "lucky@gmail.com", "+1234567"}, 
                     {"gaurav123", "+5412312", "gaurav123@skype.com"}, 
                     {"gaurav1993", "+5412312", "gaurav@gfgQA.com"}, 
                     {"raja", "+2231210", "raja@gfg.com"}, 
                     {"bahubali", "+878312", "raja"} 
                    }; 
  
    int n = sizeof arr / sizeof arr[0]; 
    findContacts(arr, n); 
    return 0; 
} 
