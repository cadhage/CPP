#include <bits/stdc++.h>
using namespace std;
struct cell{
	int x,y,dis;
};
bool isInside(int x, int y, int N) 
{ 
    if (x >= 1 && x <= N && y >= 1 && y <= N) 
        return true; 
    return false; 
} 
int minStepToReachTarget(int knightPos[], int targetPos[], 
                                                int N) 
{ 
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2}; 
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    queue<cell*> q; 
  	cell* a=new cell;
  	a->x=knightPos[0];a->y=knightPos[1];a->dis=0;
    q.push(a); 
    cell* t; 
    int x, y; 
    bool visit[N + 1][N + 1]={0};
    while(!q.empty()){
    	cell* n=q.front();
    	q.pop();
    	if(n->x==targetPos[0] && n->y==targetPos[1]){
    		return n->dis;
		}
		for(int i=0;i<8;i++){
			x=n->x+dx[i];
			y=n->y+dy[i];
			if(isInside(x,y,N)&&!visit[x][y]){
				cell* b=new cell;
				b->x=x;b->y=y;b->dis=n->dis+1;
				visit[x][y]=true;
				
				q.push(b);
			}
		}
	}
} 
int main() 
{ 
    int N = 30; 
    int knightPos[] = {1, 1}; 
    int targetPos[] = {30, 30}; 
    cout << minStepToReachTarget(knightPos, targetPos, N); 
    return 0; 
}
