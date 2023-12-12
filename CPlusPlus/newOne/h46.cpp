#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256
int getNextState(string pat,int m,int state,int x){
	if(state<m && x==pat[state]){
		return state+1;
	}
	for(int ns=state;ns>0;ns--){
		if(pat[ns-1]==x){
			int i;
			for(i=0;i<ns-1;i++){
				if(pat[i]!=pat[state-ns+1+i]){
					break;
				}
			}
			if(i==ns-1)
				return ns;
		}
	}
	return 0;
}
void computeTF(string pat,int m,int TF[][NO_OF_CHARS]){
	for(int i=0;i<=m;i++){
		for(int j=0;j<NO_OF_CHARS;j++){
			TF[i][j]=getNextState(pat,m,i,j);
		}
	}
}
void Search(string pat,string txt){
	 int m=(pat.size());
	 int n=(txt.size());
	 int TF[m+1][NO_OF_CHARS];
	 computeTF(pat,m,TF);
	 int i,state=0;
	 for(int i=0;i<n;i++){
	 	state=TF[state][txt[i]];
	 	if(state==m){
	 		cout<<"Pattern found at: "<<i-m+1<<'\n';
		 }
	 }
}
int main(){
	string txt ="ABABDABACDABABCABAB"; 
   	string pat= "ABABCABAB"; 
   	Search(pat,txt);
	return 0;
}
