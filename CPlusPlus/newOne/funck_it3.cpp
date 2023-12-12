#include <bits/stdc++.h>
using namespace std;
double sum(int n){
	return (2.0/81.0)*(pow(10,n)-1-(9*n));
}
int main(){
	int n=3;
	cout<<sum(n);
	return 0;
}
