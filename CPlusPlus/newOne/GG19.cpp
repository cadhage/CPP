#include <bits/stdc++.h>
using namespace std;
int max_intersection(int center[],int length,int k){
	sort(center,center+3);
	if(center[2]-center[0]>=2*k+length)
		return 0;
	else if(center[2]-center[0]>=2*k){
		return (2*k-(center[2]-center[0]-length));
	}
	else length;
}
int main() 
{ 
    int center[3] = { 1, 2, 3 }; 
    int L = 1; 
    int K = 1; 
    cout << max_intersection(center, L, K); 
}
