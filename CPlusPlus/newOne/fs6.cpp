#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int sol[MAX][MAX]={0};
void findUniqueRow(int a[MAX][MAX],int r,int c){ 
	for(int i = 1; i < r; i++)  
    {  
        for(int j = 1; j < c; j++)  
        {  
            if(a[i][j] == 1)  
                sol[i][j] = min(sol[i][j-1],min( sol[i-1][j],  
                                sol[i-1][j-1])) + 1;   
        }  
    }  
	int max=0,m_i=0,m_j=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(max<sol[i][j]){
				max=sol[i][j];
				m_i=i;m_j=j;
			}
		}	
	}
	for(int i=m_i;i>m_i-max;i--){
		for(int j=m_j;j>m_j-max;j--){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
	
}
int main(){
	int a[MAX][MAX]={
					{0,1,1,0,1},
					{1,1,0,1,0},
					{0,1,1,1,0},
					{1,1,1,1,0},
					{1,1,1,1,1},
					{0,0,0,0,0}	
					};
	findUniqueRow(a,6,5);
	return 0;
}
