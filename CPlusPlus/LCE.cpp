#include <bits/stdc++.h>
using namespace std;
int LCE(string s,int n,int l,int r){
	int len=0;
	while(s[r+len]==s[l+len] &&r+len<n)
		len++;
	return len;
}
void LCEQueries(string str, int n,pair<int,int> q[],int m) 
{ 
    for (int i=0; i<m; i++) 
    { 
        int L = q[i].first; 
        int R = q[i].second; 
  
        printf("LCE (%d, %d) = %d\n", L, R, 
                         LCE(str, n, L, R)); 
    } 
    return; 
} 
int main(){
	string str = "abbababba"; 
    int n = str.length(); 
  
    // LCA Queries to answer 
    pair<int,int> q[] = {{1, 2}, {1, 6}, {0, 5}}; 
    int m = sizeof(q)/sizeof(q[0]); 
  
    LCEQueries(str, n, q, m); 
	return 0;
} 
