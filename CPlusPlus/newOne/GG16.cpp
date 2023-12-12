#include <bits/stdc++.h>
using namespace std;
void bestApproximate(int x[],int y[],int n){
	double sumX=0,sumY=0,sumXY=0,sumXX=0;
	for(int i=0;i<n;i++){
		sumX+=x[i];
		sumY+=y[i];
		sumXY+=x[i]*y[i];
		sumXX+=x[i]*x[i];
	}
	double m=(n*sumXY-sumX*sumY)/(n*sumXX-(sumX*sumX));
	cout<<"m = "<<m<<'\n';
	cout<<"c = "<<(sumY-m*sumX)/n;
}
int main() 
{ 
    int x[] = { 1, 2, 3, 4, 5 }; 
    int y[] = { 14, 27, 40, 55, 68 }; 
    int n = sizeof(x) / sizeof(x[0]); 
    bestApproximate(x, y, n); 
    return 0; 
} 
