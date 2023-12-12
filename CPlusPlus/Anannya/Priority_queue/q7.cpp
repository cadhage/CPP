#include <bits/stdc++.h>
using namespace std;
int maxDivide(int a,int b){
	while(a%b==0){
		a=a/b;
	}
	return a;
}
int isUgly(int n){
	n=maxDivide(n,2);
	n=maxDivide(n,3);
	n=maxDivide(n,5);
	return n==1?1:0;
}
int getNthUglyNo(int n){
	int i=1,j=1;
	while(n>j){
		i++;
		if(isUgly(i))
			j++;
	}
	return i;
}
int main() 
{ 
    int no = getNthUglyNo(150); 
    printf("150th ugly no. is %d ",  no); 
    //getchar(); 
    return 0; 
}
