#include <bits/stdc++.h>
using namespace std;
int countParenth(char symb[], char oper[], int n) 
{ 
	int F[n][n], T[n][n]; 
	for (int i = 0; i < n; i++) 
	{ 
		F[i][i] = (symb[i] == 'F')? 1: 0; 
		T[i][i] = (symb[i] == 'T')? 1: 0; 
	} 
	for (int gap=1; gap<n; ++gap) 
	{ 
		for (int i=0, j=gap; j<n; ++i, ++j) 
		{ 
			T[i][j] = F[i][j] = 0; 
			for (int g=0; g<gap; g++) 
			{ 
				// Find place of parenthesization using current value 
				// of gap 
				int k = i + g; 

				// Store Total[i][k] and Total[k+1][j] 
				int tik = T[i][k] + F[i][k]; 
				int tkj = T[k+1][j] + F[k+1][j]; 

				// Follow the recursive formulas according to the current 
				// operator 
				if (oper[k] == '&') 
				{ 
					T[i][j] += T[i][k]*T[k+1][j]; 
					F[i][j] += (tik*tkj - T[i][k]*T[k+1][j]); 
				} 
				if (oper[k] == '|') 
				{ 
					F[i][j] += F[i][k]*F[k+1][j]; 
					T[i][j] += (tik*tkj - F[i][k]*F[k+1][j]); 
				} 
				if (oper[k] == '^') 
				{ 
					T[i][j] += F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j]; 
					F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j]; 
				} 
			} 
		} 
	} 
	return T[0][n-1]; 
}
//int countParenth(string s,string op,int n){
//	int f[n][n],t[n][n];
//	for(int i=0;i<n;i++){
//		f[i][i]=(s[i]=='F')?1:0;
//		t[i][i]=(s[i]=='T')?1:0;
//	}
//	for(int g=1;g<n;g++){
//		for(int i=0,j=g;j<n;i++,j++){
//			t[i][j]=f[i][j]=0;
//			for(int gg=0;gg<g;gg++){
//				int k=i+gg;
//				int tik=t[i][k]+f[i][k];
//				int tkj=t[k+1][j]+f[k+1][j];
//				if(op[k]=='&'){
//					t[i][j]+=t[i][k]*t[k+1][j];
//					f[i][j]+=(tik*tkj-t[i][k]*t[k+1][j]);
//				}
//				if(op[k]='|'){
//					f[i][j]+=f[i][k]*f[k+1][j];
//					t[i][j]+=(tik*tkj-f[i][k]*f[k+1][j]);
//				}
//				if(op[k]='^'){
//					t[i][j]+=f[i][k]*t[k+1][j]+t[i][k]*f[k+1][j];
//					f[i][j]+=t[i][k]*t[k+1][j]+f[i][k]*f[k+1][j];
//					
//				}
//			}
//		}
//	}
//	return t[0][n-1];
//}
int main(){
	char s[]="TTFT";
	char op[]="|&^";
	int n=strlen(s);
	cout<<countParenth(s,op,n);
	return 0;
}
