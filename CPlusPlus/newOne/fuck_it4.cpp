#include <bits/stdc++.h>
using namespace std;
double sum(int n){
	return (5.0/81.0)*(pow(10,n)-1-(45*n));
} 
int main(){
	cout<<sum(3);
	return 0;
} 
