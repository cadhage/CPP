#include <bits/stdc++.h>
using  namespace std;
int minPalPartition(string s){
	int n=s.size();
	int C[n][n];  
    bool P[n][n];   
    for (int i = 0; i < n; i++)  
    {  
        P[i][i] = true;  
        C[i][i] = 0;  
    }  
  
	for(int L=2;L<=n;L++){
		for(int i=0;i<n-L+1;i++){
			int j=i+L-1;
			if(L==2)
				P[i][j]=(s[i]==s[j]);
			else
				P[i][j]=(s[i]==s[j])&&P[i+1][j-1];
			if(P[i][j])
				C[i][j]=0;
			else{
				C[i][j]=INT_MAX;
				for(int k=i;k<j;k++){
					C[i][j]=min(C[i][j],C[i][k]+C[k+1][j]+1);
				}
			}
		}
	}
	return C[0][n-1];
}
int main()  
{  
    string str = "ababbbabbababa";  
    cout<<"Min cuts needed for Palindrome Partitioning is "<<minPalPartition(str);  
    return 0;  
}  
