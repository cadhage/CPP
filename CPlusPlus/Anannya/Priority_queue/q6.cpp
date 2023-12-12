#include <bits/stdc++.h>
using namespace std;
void minSpacePreferLarge(int wall,int m,int n){
	int ms=0,ns=0,empty=0;
	int p=0,q=0,rem=wall;
	while(wall>=0){
		p=wall/m;
		rem=wall%m;
		if(rem<=empty){
			ms=p;
			ns=q;
			empty=rem;
		}
		q++;
		wall+=-n;
		
	}
	cout<<ms<<" "<<ns<<" "<<empty<<'\n';
	
}
int main(){
	 int wall = 24, m = 3, n = 5; 
    minSpacePreferLarge(wall, m, n); 
  
    wall = 24, m = 4, n = 7; 
    minSpacePreferLarge(wall, m, n); 
	return 0;
}
