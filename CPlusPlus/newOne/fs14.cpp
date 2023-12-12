#include <bits/stdc++.h>
using namespace std;
vector<bool> v(1000,false);
int solver(int moves[],int n){
	queue<pair<int,int>> q;
	v[0]=true;
	q.push({0,0});
	pair<int,int> qe;
	while(!q.empty()){
		qe=q.front();
		int u=qe.first;
		if(u==n-1)
			break;
		q.pop();
		for(int j=u+1;j<=(u+6)&&j<n;j++){
			if(!v[j]){
				pair<int,int> a;
				a.second=(qe.second+1);
				v[j]=true;
				if(moves[j]!=-1){
					a.first=moves[j];
				}
				else{
					a.first=j;
				}
				q.push(a);
			}
		}
	}
	return qe.second;
}
int main(){
	int n=30;
	int moves[n];
	for(int i=0;i<n;i++){
		moves[i]=-1;
	}
	moves[2]=21;
	moves[4]=7;
	moves[10]=25;
	moves[19]=28;
	moves[26]=0;
	moves[20]=8;
	moves[16]=3;
	moves[18]=6;
	cout<<solver(moves,n);
	return 0;
}
