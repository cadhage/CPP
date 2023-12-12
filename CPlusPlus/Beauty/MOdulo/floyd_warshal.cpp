#include <bits/stdc++.h>
using namespace std;
#define INF 999
void floydWarshall(int a[][4]){
	int adj[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			adj[i][j]=a[i][j];
		}
	}
	for(int k=0;k<4;k++){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(adj[i][j]>adj[i][k]+adj[k][j])
					adj[i][j]=adj[i][k]+adj[k][j];
			}
		}
	}
	for(int i=0;i<4;i++){
		if(adj[i][i]<0){
			cout<<"Cycle Detected\n";
			return;
		}
	} 
	for (int i = 0; i < 4; i++)  
    {  
        for (int j = 0; j < 4; j++)  
        {  
            if (adj[i][j] == INF)  
                cout<<"INF"<<"\t";  
            else
                cout<<adj[i][j]<<"\t";  
        }  
        cout<<endl;  
    } 

}
int main()  
{  
    /* Let us create the following weighted graph  
            10  
    (0)------->(3)  
        |     /|\  
    5 |     |  
        |     | 1  
    \|/     |  
    (1)------->(2)  
            3     */
    int graph[4][4] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  
    // Print the solution  
    floydWarshall(graph);
    cout<<"\n\n";
	  int g[4][4] = { {0   , 1   , INF , INF}, 
                        {INF , 0   , -1  , INF}, 
                        {INF , INF , 0   ,  -1}, 
                        {-1  , INF , INF ,   0}};
	floydWarshall(g);  
    return 0;  
}  
