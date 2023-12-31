#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256
void badCharHeuristic(string str,int size,int badChar[NO_OF_CHARS]){
	int i=0;
	for(int i=0;i<NO_OF_CHARS;i++){
		badChar[i]=-1;
		for(int i=0;i<size;i++){
			badChar[(int)str[i]]=i;
		}
		for(int i=0;i<size;i++){
			badChar[(int)str[i]]=i;
		}
	}
}
void Search(string pat,string txt){
	int m=pat.size();
	int n=txt.size();
	int badChar[NO_OF_CHARS];
	badCharHeuristic(pat,m,badChar);
	int s=0;
	while(s<=(n-m)){
		int j=m-1;
		while(j>=0 && pat[j]==txt[s+j])
			j--;
		if(j<0){
			cout<<"at: "<<s<<'\n';
			s+=(s+m<n)?m-badChar[txt[s+m]]:1;
		}
		else{
			s+=max(1,j-badChar[txt[s+j]]);
		}
	}
}
int main(){
	string txt ="ABABDABACDABABCABAB"; 
   	string pat= "ABABCABAB"; 
   	Search(pat,txt);
	return 0;
}
