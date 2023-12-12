#include <bits/stdc++.h>
using namespace std;
void solver(int s[],int f[],int n){
	int i=0;
	for(int j=1;j<n;j++){
		if(s[j]>=f[i]){
			cout<<j<<' ';
			i=j;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int s[] =  {1, 3, 0, 5, 8, 5}; 
    int f[] =  {2, 4, 6, 7, 9, 9}; 
    int n = sizeof(s)/sizeof(s[0]); 
    solver(s, f, n); 
	return 0;
}
