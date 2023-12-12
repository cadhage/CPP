#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256
void preprocess_strong_suffix(int *shift,int *bpos,
		string pat,int m){
	int i=m,j=m+1;
	bpos[i]=j;
	while(i>0){
		while(j<=m&& pat[i-1]!=pat[j-1]){
			if(shift[j]==0){
				shift[j]=j-i;
			}
			j=bpos[j];
		}
		j--;i--;
		bpos[i]=j;
	}
}
void preprocess_case2(int *shift,int *bpos,string pat,int m){
	int j=bpos[0];
	for(int i=0;i<=m;i++){
		if(shift[i]==0){
			shift[i]=j;
		}
		if(i==j){
			j=bpos[j];
		}
	}
}
void Search(string pat,string txt){
	int s=0,j;
	int m=pat.size();
	int n=txt.size();
	int bpos[m+1],shift[m+1]={0};
	preprocess_strong_suffix(shift,bpos,pat,m);
	preprocess_case2(shift,bpos,pat,m);
	while(s<=(n-m)){
		j=m-1;
		while(j>=0 && pat[j]==txt[s+j])
			j--;
		if(j<0){
			cout<<"at: "<<s<<'\n';
			s+=shift[0];
		}
		else{
			s+=shift[j+1];
		}
	}
}
int main(){
	string txt ="ABABDABACDABABCABAB"; 
   	string pat= "ABABCABAB"; 
   	Search(pat,txt);
	return 0;
}
