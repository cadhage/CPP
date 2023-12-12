#include <bits/stdc++.h>
using namespace std;
bool adj[100][100];
char result[10000];
bool findthePath(string S,int x){
	//string result="";
	result[0]=x+'0';
	int i=0;
	for(auto c:S){
		if(adj[x][c-'A']||adj[c-'A'][x]){
			x=c-'A';
		}
		else if(adj[x][c-'A'+5]||adj[c-'A'+5][x])
			x=c-'A'+5;
		else return false;
		result[i++]=x+'0';
	}
//	cout<<result<<' ';
	return true;
}
int main(){
	adj[0][1] = adj[1][2] = adj[2][3] = adj[3][4] =  
    adj[4][0] = adj[0][5] = adj[1][6] = adj[2][7] = 
    adj[3][8] = adj[4][9] = adj[5][7] = adj[7][9] = 
    adj[9][6] = adj[6][8] = adj[8][5] = true; 
      
    // path to be checked 
    string S = "ABB"; 
      
    if (findthePath(S, S[0] - 'A') ||  
        findthePath(S, S[0] - 'A' + 5)) { 
        cout << result; 
    } else { 
        cout << "-1"; 
    } 
	return 0;  
}
