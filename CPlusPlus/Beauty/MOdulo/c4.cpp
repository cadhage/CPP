#include <bits/stdc++.h>
using namespace std;
#define LIMIT 20
#define MAX_NOTE_VALUE 1000
int maxDivide(int n,int d){
	while(n%d==0){
		n=n/d;
	}
	return n;
}
bool UglyNo(int n){
	n=maxDivide(n,2);
	n=maxDivide(n,3);
	n=maxDivide(n,5);
	if(n==1)
		return true;
	else return false;	
}
int getNthUglyNo(int n){
	int c=0,res=0;
	for(int i=1;c<n;i++){
		if(UglyNo(i)){
			c++;
		}
		if(c==n)
			res=i;
	}
	return res;
}
int main() 
{ 
    int no = getNthUglyNo(150); 
    printf("150th ugly no. is %d ",  no); 
   // getchar(); 
    return 0; 
} 
