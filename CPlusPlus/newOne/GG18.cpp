#include <bits/stdc++.h>
using namespace std;
bool isBetween(int x,int y,int z){
	if(z>=min(x,y)&&z<=max(x,y))
		return true;
	return false;
}
bool canJoin(int x[],int y[],int i,int j,int k){
	return (x[k]==x[i]||x[k]==x[j])&&isBetween(y[i],y[j],y[k])||
	(y[k]==y[i]||y[k]==y[j]&& isBetween(x[i],x[j],x[k]));
}
int countLineSegments(int x[],int y[]){
	if((x[0]==x[1] &&x[1]==x[2])||
	(y[0]==y[1]&&y[1]==y[2]))
		return 1;
	else if(canJoin(x,y,0,1,2)||
		canJoin(x,y,0,2,1)||canJoin(x,y,1,2,0))	
			return 2;
	else return 3;
}
int main() 
{ 
    int x[3], y[3]; 
    x[0] = 1; y[0] = 1; 
    x[1] = 2; y[1] = 3; 
    x[2] = 3; y[2] = 2; 
    cout << countLineSegments(x, y); 
    return 0; 
}
