#include <bits/stdc++.h>
using namespace std;
int XoR(int n){
	switch(n&3){
		case 0: return n;
		case 1:return 1;
		case 2: return n+1;
		case 3: return 0;
	}
	return -1;
}
int  main(){
	int n=5;
	cout<<XoR(n);
	return 0;
}
