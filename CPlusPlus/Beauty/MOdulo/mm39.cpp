#include<bits/stdc++.h>  
using namespace std; 
int dp[1000][1000]={0};
int lcs( char *X, char *Y, int m, int n )  
{   
    for (int i = 0; i <= m; i++)  
    {  
        for (int j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            dp[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            dp[i][j] = dp[i - 1][j - 1] + 1;  
      
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
        }  
    }  
    return dp[m][n];  
}  
int main()  
{  
    char X[] = "AGGTAB";  
    char Y[] = "GXTXAYB";  
    int m = strlen(X);  
    int n = strlen(Y);  
    cout << "Length of LCS is " 
         << lcs( X, Y, m, n );  
    return 0;  
}  
