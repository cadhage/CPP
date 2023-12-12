#include <bits/stdc++.h>
using namespace std;
void printIntegerPoint(int pointU[],int pointV[]){
	int A=(pointU[1]-pointV[1]);
	int B=(pointV[0]-pointU[0]);
	int C=(pointU[0]*(pointU[1]-pointV[1])+
			pointU[1]*(pointV[0]-pointU[0]));
	int x,y;
	int g=gcdExtended(A,B,x,y);
	if(C%g!=0)
		cout<<"No possible";
	else{
		cout<<"Integer Point: "<<(x<<C/g)<<" "<<
		(y*C/g)<<'\n';
	}
}
int main() 
{ 
    int pointU[] = {1, -1}; 
    int pointV[] = {-4, 1}; 
  
    printIntegerPoint(pointU, pointV); 
    return 0; 
}
