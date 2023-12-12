#include <bits/stdc++.h>
using namespace std;
const int MAX=100;
int getTrace(int a[][MAX],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i][i];
	}
	return sum;
}
void mul(int a[][MAX],int b[][MAX],int c[][MAX],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c[i][j]=0;
			for(int k=0;k<n;k++)
				c[i][j]+=a[i][k]*b[k][j];
		}
	}
}
int triangleInGraph(int a[][MAX],int n){
	int aux1[MAX][MAX],aux2[MAX][MAX];
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			aux1[i][j]=aux2[i][j]=0;
		}
	}
	mul(a,a,aux1,n);
	mul(a,aux1,aux2,n);
	int trace=getTrace(aux2,n);
	return trace/6;
}
int main() 
{ 
  
    int graph[][MAX] = {{0, 1, 1, 0}, 
                       {1, 0, 1, 1}, 
                       {1, 1, 0, 1}, 
                       {0, 1, 1, 0} 
                      }; 
  
    printf("Total number of Triangle in Graph : %d\n", 
            triangleInGraph(graph,4)); 
    return 0; 
}
