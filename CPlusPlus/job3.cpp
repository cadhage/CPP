#include <bits/stdc++.h>
using namespace std;
int nCrModPFermat(int n,int k){
	int res=1;
	if(k>n-k)
		k=n-k;
	for(int i=0;i<k;i++){
		res*=(n-i);
		res/=(i+1);
	}	
	return res;
}
int main(){
	    int n = 8, r = 2, p = 13; 
    cout << "Value of nCr % p is "
         << nCrModPFermat(n, r); 
    return 0; 
}

