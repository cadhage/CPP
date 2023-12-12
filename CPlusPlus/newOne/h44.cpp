#include <bits/stdc++.h>
using namespace std;
void computeLPSA(string pat,int m,int *lps){
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<m){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0){
				len=lps[len-1];
			}
			else {
				lps[i]=0;
				i++;
			}
		}
	}
}
void KMPSearch(string pat,string txt){
	int m=pat.size();
	int n=txt.size();
	int lps[m]={0};
	computeLPSA(pat,m,lps);
	int i=0,j=0;
	while(i<n){
		if(txt[i]==pat[j]){
			i++;j++;
		}
		if(j==m)
		{
			cout<<"at: "<<i-j<<'\n';
			j=lps[j-1];
		}
		else if(i<n && pat[j]!=txt[i]){
			if(j!=0){
				j=lps[j-1];
			}
			else i++;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string txt = "ABABDABACDABABCABAB"; 
   	string pat= "ABABCABAB"; 
   	KMPSearch(pat,txt);
	return 0;
}
