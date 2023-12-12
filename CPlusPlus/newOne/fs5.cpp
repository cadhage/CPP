#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int n=4,m=5;
void printArr(int a[MAX][MAX]){
	set<string> st;
	for(int i=0;i<=n;i++){
		string s="";
		for(int j=0;j<m;j++){
			s+=to_string(a[i][j]);
		}
		if(st.count(s)==0){
			st.insert(s);
			cout<<s<<'\n';
		}
	}
}
int main(){
	int a[MAX][MAX]={{0,1,0,0,1},
					{1,0,1,1,0},
					{0,1,0,0,1},
					{1,1,1,0,0}};
	printArr(a);	
}
