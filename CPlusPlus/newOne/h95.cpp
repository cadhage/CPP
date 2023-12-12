// C++ program to find out whether a 
// given graph is Bipartite or not 
#include <iostream> 
#include <queue> 
#define VV 4 
using namespace std; 
struct queueEntry{
	int v,dist;	
};
bool V[1000]={false};
int getMinDiceThrows(int move[],int n){ 
	//queue <queueEntry> q; 
	V[0]=true;
	queue<queueEntry> q;
	queueEntry s={0,0};
	q.push(s);
	queueEntry qu;
	while (!q.empty()) 
	{ 	
		qu = q.front();
		int v=qu.v; 
		if (v ==n-1) 
			break;
		q.pop();
		for (int j = v+1; j <= v+6 && j<n; ++j) 
		{ 
			if (!V[j]) 
			{ 
				queueEntry a;
				a.dist=qu.dist+1;
				V[j]=true;
				if(move[j]!=-1)
					a.v=move[j];
				else
					a.v=j;
				q.push(a); 
			} 
		} 
	} 
	return qu.dist; 
}
int main() 
{ 
	int N = 30; 
    int moves[N]; 
    for (int i = 0; i<N; i++) 
        moves[i] = -1; 
  
    // Ladders 
    moves[2] = 21; 
    moves[4] = 7; 
    moves[10] = 25; 
    moves[19] = 28; 
  
    // Snakes 
    moves[26] = 0; 
    moves[20] = 8; 
    moves[16] = 3; 
    moves[18] = 6; 
  
    cout << "Min Dice throws required is " << getMinDiceThrows(moves, N); 
    return 0; 
//	return 0; 
} 

