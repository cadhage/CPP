#include <bits/stdc++.h>
using namespace std;
int maxDivide(int a,int b){
	while(a%b==0)
		a/=b;
	return a;
}
bool isUgly(int n){
	n=maxDivide(n,2);
	n=maxDivide(n,3);
	n=maxDivide(n,5);
	return n==1?true:false;
}
int getUglyNumber(int n){
	int i=1;
	int count=1;
	while(n>count){
		i++;
		if(isUgly(i)){
			count++;
		}
	}
	return i;
}
int main(){
	cout<<getUglyNumber(150);
	return 0;
}
