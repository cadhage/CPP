#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

vector<int> edges[MAX];
vector<int> vis[MAX];

int main() {

    int numNodes, numEdges; // number of edges
    scanf("%d", &numNodes);
    numEdges=numNodes-1;
    int level[numNodes]={-1};

    for (int i = 0; i < numNodes; i++) {
        level[i] = -1;
    }
    for (int i = 0; i < numEdges; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        edges[x-1].push_back(y);
        edges[y-1].push_back(x);
	}
    level[0] = 0;
    for (int i = 0; i < numNodes; i++) {
        int l = edges[i].size();
        for (int j = 0; j < l; j++)
        {
        if (((level[edges[i][j]-1] < level[i]) && (edges[i][j] > i+1)) || (level[edges[i][j]-1] == -1)) {
            level[edges[i][j]-1] = level[i] + 1;
            }
        }
    }
    for(int i = 0; i < numNodes; i++) {
        printf("Level of node %d is: %d\n", i+1, level[i]);
    }

    return 0;
}
