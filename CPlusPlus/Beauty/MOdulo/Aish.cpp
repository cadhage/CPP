#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
#define N 8
bool isSafe(int x,int y,int sol[][N]){
	return (x>=0 && x<N && y>=0&&y<N&&sol[x][y]==0);
}
void printSolution(int sol[][N]){
	for(int x=0;x<N;x++){
		for(int y=0;y<N;y++){
			cout<<sol[x][y]<<' ';
		}
		cout<<'\n';
	}
}
int solveKTUtil(int x,int y,int  movei,int sol[][N],int xMove[N],int yMove[N]){
	int k,next_x,next_y;
	if(movei==N*N)
		return 1;
	for(int k=0;k<8;k++){
		next_x=x+xMove[k];
		next_y=y+yMove[k];
		if(isSafe(next_x,next_y,sol)){
			sol[next_x][next_y]=movei;
			if(solveKTUtil(next_x,next_y,movei+1,sol,xMove,yMove)){
				return 1;
			}
			else
				sol[next_x][next_y]=0;
		}
	}
	return 0;
}
void solveKT(){
	int sol[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			sol[i][j]=0;
		}
	}
	int xMove[]={2,1,-1,-2,-2,-1,1,2};
	int yMove[]={1,2,2,1,-1,-2,-2,-1};
	if(solveKTUtil(0,0,1,sol,xMove,yMove)){
		cout<<"Solvtion doesnt exit"<<'\n';
	}
	else
		printSolution(sol);
}

int main(){
	solveKT();
	return 0;
}
